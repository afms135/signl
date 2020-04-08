#include "effect.h"
#include <cmath>
#include <vector> // std::vector()
#include "../FFTConvolver/FFTConvolver.h"
#include "../FFTConvolver/TwoStageFFTConvolver.h"
#include "ir/ir_cement.h"
#include "ir/ir_sanctuary.h"
#include "ir/ir_drum.h"
#include "ir/ir_ruby.h"
#include "ir/ir_trig.h"
#include "ir/ir_columns.h"
#include "ir/ir_lodge.h"
#include "ir/ir_columns_long.h"
#include "ir/ir_cave.h"
#include "ir/ir_hall.h"

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
	conv_buf1(CONV_BUFFER_LENGTH),
	conv_buf2(CONV_BUFFER_LENGTH),
	in_buf(CONV_BUFFER_LENGTH),
	in_buf_copy(CONV_BUFFER_LENGTH),
	new_val(0.0),
	type(0.0),
	size(0.5),
	drywet(0.5),
	level(0.5)
	{
		conv1.init(32,1024,&ir_cement[0],16384);
		conv2.init(128,2048,&ir_sanctuary[0],65536);
	}

	float operator()(float in) override
	{
		in_buf[buf_idx++] = in;
		if(new_val != type)
		{
			type = new_val;
			change_convolvers();
		}
		if (buf_idx == CONV_BUFFER_LENGTH)
		{
			buf_idx = 0;
			in_buf_copy = in_buf;
			conv1.process(&in_buf_copy[0],&conv_buf1[0],CONV_BUFFER_LENGTH);
			conv2.process(&in_buf[0],&conv_buf2[0],CONV_BUFFER_LENGTH);

		}
		float out = 0.0;
//		float out = conv_buf1[buf_idx]*size;
		out = (conv_buf1[buf_idx]*(1-size)) + (conv_buf2[buf_idx]*size);
		out = (out * drywet) + (in_buf[buf_idx] * (1-drywet));
		return out * level;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
		{
			new_val = (float)((int)(v*5))/4.0;
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
			return "Type";
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
			return type;
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
	void change_convolvers()
	{
		int type_int = int(type*5);
		switch(type_int)
		{
			case 0:	conv1.init(32,1024,&ir_cement[0],16384);
				conv2.init(128,2048,&ir_sanctuary[0],65536);
				break;
			case 1:	conv1.init(32,1024,&ir_drum[0],16384);
				conv2.init(128,2048,&ir_ruby[0],32768);
				break;
			case 2:	conv1.init(32,1024,&ir_trig[0],32768);
				conv2.init(128,2048,&ir_columns[0],65536);
				break;
			case 3:	conv1.init(32,1024,&ir_lodge[0],16384);
				conv2.init(128,2048,&ir_columns_long[0],98304);
				break;
			default:conv1.init(32,1024,&ir_cave[0],16384);
				conv2.init(128,256,&ir_hall[0],131072);
				break;
		}
	}

	std::vector<float> conv_buf1;
	std::vector<float> conv_buf2;
	std::vector<float> in_buf;
	std::vector<float> in_buf_copy;
	unsigned int buf_idx = 0;

	float new_val;
	float type;
	float size;
	float drywet;
	float level;

	fftconvolver::TwoStageFFTConvolver conv1;
	fftconvolver::TwoStageFFTConvolver conv2;
};

PLUGIN_API
