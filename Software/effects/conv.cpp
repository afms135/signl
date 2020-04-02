#include "effect.h"
#include <cmath>

/* 
This should a power of 2 no larger than 512 @ sample_rate = 48kHz:

   Buffer length | Audio delay (ms)
   ===============================
    1024         | 21.33
     512         | 10.67
     256         |  5.33
     128         |  2.67
      64         |  1.33
*/

#define CONV_BUFFER_LENGTH 512

class plugin : public effect
{
public:
	plugin(unsigned int rate)
	{
	}

	float operator()(float in) override
	{
		in_buf[in_buf_idx++] = in;
		in_buf_idx %= CONV_BUFFER_LENGTH;
		return in_buf[in_buf_idx];
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
	float in_buf[CONV_BUFFER_LENGTH] = {0.0};
	unsigned int in_buf_idx = 0;
};

PLUGIN_API
