#include "effect.h"
#include <cmath>
#include <thread>
#include <algorithm>

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

#define CONV_BUFFER_LENGTH 128

class plugin : public effect
{
public:
	plugin(unsigned int rate)
	{
	}

	float operator()(float in) override
	{
		in_buf[in_buf_idx++] = in;
		if (in_buf_idx == CONV_BUFFER_LENGTH)
		{
			in_buf_idx = 0;
			std::copy(conv_buf, conv_buf+CONV_BUFFER_LENGTH, out_buf);
			std::copy(in_buf, in_buf+CONV_BUFFER_LENGTH, conv_buf);
			std::thread t(convolve,conv_buf);
			t.detach();
		}

		return out_buf[in_buf_idx];
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
	static void convolve(float* conv_buf)
	{
	}

	float in_buf[CONV_BUFFER_LENGTH] = {0.0};
	float conv_buf[CONV_BUFFER_LENGTH] = {0.0};
	float out_buf[CONV_BUFFER_LENGTH] = {0.0};
	unsigned int in_buf_idx = 0;

//	std::thread t;
};

PLUGIN_API
