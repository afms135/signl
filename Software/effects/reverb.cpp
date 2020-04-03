#include "effect.h"
#include <cmath>
#include <thread> // std::thread()
#include <algorithm> // std::copy() and .assign() and std::transform()
#include <vector> // std::vector()
#include <functional> // std::plus()
#include "../FFTConvolver/FFTConvolver.h"
#include "ir.h"

/*
This should a power of 2 no larger than 128 @ sample_rate = 48kHz:

   Buffer length | Audio delay (ms) | Worst case (5*delay)
   =======================================================
    1024         | 21.33            | 106.67
     512         | 10.67            |  53.33
     256         |  5.33            |  26.67
     128         |  2.67            |  13.33
      64         |  1.33            |   6.67
*/

// Note ^^ This is now  doubled as we must wait for a full input buffer
//         before we can process it. Would be back down to the above times
//         if we pass a buffer straight to the plugin () from jack_client::process

// Note ^^ Now that we're using FFTConvolver, will have to look into this again.

#define CONV_BUFFER_LENGTH 128
#define KERNEL_SIZE 32768

class plugin : public effect
{
public:
	plugin(unsigned int rate) :
	kernel(KERNEL_SIZE),
	in_buf(CONV_BUFFER_LENGTH),
	conv_buf(CONV_BUFFER_LENGTH),
	overlap_buf(KERNEL_SIZE - 1)
	{
		filter.init(CONV_BUFFER_LENGTH,&ir[0],ir.size());
	}

	float operator()(float in) override
	{
		in_buf[buf_idx++] = in;
		if (buf_idx == CONV_BUFFER_LENGTH)
		{
			buf_idx = 0;
			filter.process(&in_buf[0],&conv_buf[0],CONV_BUFFER_LENGTH);
		}
		return conv_buf[buf_idx];
	}

	void paramset(param p, float v) override
	{
	}

	std::string name() override
	{
		return "Reverb";
	}

	std::string paramname(param p) override
	{
		return "";
	}

	float paramval(param p) override
	{
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_EMPTY_BOX;
	}

private:
	void convolve(std::vector<float> &input)
	{
		unsigned int paddedLength = input.size() + kernel.size() - 1;
		std::vector<float> output(paddedLength); //zeros

		for(unsigned int i=0; i<paddedLength; i++) //index into output vector
		{
			int startk = (i >= input.size()) ? i - input.size() + 1 : 0;
			int endk = (i < kernel.size()) ? i : kernel.size() - 1;

			for( int kernel_idx = startk; kernel_idx < endk; kernel_idx++ )
				output[i] += kernel[kernel_idx]*input[i-kernel_idx];
		}
		// Return convolved output
		conv_buf.assign(output.begin(),output.begin() + CONV_BUFFER_LENGTH);
		// Add the previous overlap to the first values of the result
		std::transform(overlap_buf.begin(), overlap_buf.end(), conv_buf.begin(), conv_buf.begin(), std::plus<float>());
		// Store the overlap
		overlap_buf.assign(output.begin() + CONV_BUFFER_LENGTH, output.end());
	}

	fftconvolver::FFTConvolver filter;

	std::vector<float> kernel;
	std::vector<float> in_buf;
	std::vector<float> conv_buf;
	std::vector<float> overlap_buf;
	unsigned int buf_idx = 0;
};

PLUGIN_API
