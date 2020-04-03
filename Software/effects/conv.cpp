#include "effect.h"
#include <cmath>
#include <thread> // std::thread()
#include <algorithm> // std::copy() and .assign() and std::transform()
#include <vector> // std::vector()
#include <functional> // std::plus()

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

#define KERNEL_SIZE 64

class plugin : public effect
{
public:
	plugin(unsigned int rate) :
	kernel(KERNEL_SIZE,1.0f/KERNEL_SIZE),
	overlap_buf(KERNEL_SIZE - 1)
	{
	}

	float* operator()(float* in, const unsigned int frames) override
	{
		conv_buf.assign(in,in + frames);
		convolve(std::ref(conv_buf),frames);
//		std::thread t(&plugin::convolve,this,std::ref(conv_buf));
//		t.detach();
		std::copy(conv_buf.begin(),conv_buf.end(),in);
		return in;
	}

	void paramset(param p, float v) override
	{
	}

	std::string name() override
	{
		return "Convolution";
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
	void convolve(std::vector<float> &input, const unsigned int frames)
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
		conv_buf.assign(output.begin(),output.begin() + frames);
		// Add the previous overlap to the first values of the result
		std::transform(overlap_buf.begin(), overlap_buf.end(), conv_buf.begin(), conv_buf.begin(), std::plus<float>());
		// Store the overlap
		overlap_buf.assign(output.begin() + frames, output.end());
	}

	std::vector<float> kernel;
	std::vector<float> conv_buf;
	std::vector<float> overlap_buf;
	unsigned int buf_idx = 0;
};

PLUGIN_API
