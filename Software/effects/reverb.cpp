#include "effect.h"
#include <cmath>
#include <vector> // std::vector()
#include "../FFTConvolver/FFTConvolver.h"
#include "ir_cave.h"
#include "ir_church.h"

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

#define CONV_BUFFER_LENGTH 256

class plugin : public effect
{
public:
	plugin(unsigned int rate) :
	in_buf(CONV_BUFFER_LENGTH),
	conv_buf1(CONV_BUFFER_LENGTH),
	conv_buf2(CONV_BUFFER_LENGTH),
	tail(0.5),
	size(0.5),
	drywet(0.5),
	level(0.5)
	{
		conv1.init(CONV_BUFFER_LENGTH,&ir_cave[0],ir_cave.size());
		conv2.init(CONV_BUFFER_LENGTH,&ir_church[0],ir_church.size());
	}

	float operator()(float in) override
	{
		in_buf[buf_idx++] = in;
		if (buf_idx == CONV_BUFFER_LENGTH)
		{
			buf_idx = 0;
			conv1.process(&in_buf[0],&conv_buf1[0],CONV_BUFFER_LENGTH);
			conv2.process(&in_buf[0],&conv_buf2[0],CONV_BUFFER_LENGTH);
		}
		float out = (conv_buf2[buf_idx]*size) + (conv_buf1[buf_idx]*(1-size));
		out = (out * drywet) + (in_buf[buf_idx] * (1-drywet));
		return out * level;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
		{
			tail = v;
		}
		else if(p == PARAM_B)
		{
			size = v;
		}
		else if(p == PARAM_C)
		{
			drywet = v;
		}
		else if(p == PARAM_D)
		{
			level = v;
		}
	}

	std::string name() override
	{
		return "Reverb";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Tail";
		else if(p == PARAM_B)
			return "Size";
		else if(p == PARAM_C)
			return "Dry-Wet";
		else if(p == PARAM_D)
			return "Level";
		return "";	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return tail;
		else if(p == PARAM_B)
			return size;
		else if(p == PARAM_C)
			return drywet;
		else if(p == PARAM_D)
			return level;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_EMPTY_BOX;
	}

private:
	fftconvolver::FFTConvolver conv1;
	fftconvolver::FFTConvolver conv2;

	std::vector<float> in_buf;
	std::vector<float> conv_buf1;
	std::vector<float> conv_buf2;
	unsigned int buf_idx = 0;

	float tail;
	float size;
	float drywet;
	float level;
};

PLUGIN_API
