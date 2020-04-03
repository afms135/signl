#include "effect.h"
#include <cmath>
#include <thread> // std::thread()
#include <algorithm> // std::copy()
#include <vector> // std::vector()

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

#define CONV_BUFFER_LENGTH 256

class plugin : public effect
{
public:
	plugin(unsigned int rate) : kernel(128,1.0f)
	{
	}

	float operator()(float in) override
	{
		in_buf[buf_idx++] = in;
		if (buf_idx == CONV_BUFFER_LENGTH)
		{
			buf_idx = 0;
			std::copy(conv_buf, conv_buf+CONV_BUFFER_LENGTH, out_buf);
			std::copy(in_buf, in_buf+CONV_BUFFER_LENGTH, conv_buf);
			std::thread t(&plugin::convolve,this,conv_buf);
			t.detach();
		}

		return out_buf[buf_idx];
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
	void convolve(float* conv_buf)
	{
		std::vector<float> input(conv_buf, conv_buf + CONV_BUFFER_LENGTH);

		unsigned int paddedLength = input.size() + kernel.size() - 1;
		std::vector<float> convolved(paddedLength); //zeros

		for(unsigned int i=0; i<paddedLength; i++) //index into 'convolved' vector
		{
			int startk = (i >= input.size()) ? i - input.size() + 1 : 0;
			int endk = (i < kernel.size()) ? i : kernel.size() - 1;

			for( int kernel_idx = startk; kernel_idx < endk; kernel_idx++ )
				convolved[i] += kernel[kernel_idx]*input[i-kernel_idx];
		}
		conv_buf = &convolved[0];
	}

	float in_buf[CONV_BUFFER_LENGTH] = {0.0};
	float conv_buf[CONV_BUFFER_LENGTH] = {0.0};
	float out_buf[CONV_BUFFER_LENGTH] = {0.0};
	unsigned int buf_idx = 0;

	std::vector<float> kernel;
};

PLUGIN_API
