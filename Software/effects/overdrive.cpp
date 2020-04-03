#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin(unsigned int rate) : threshold(1.0/3.0)
	{
	}

	float* operator()(float* in, const unsigned int frames) override
	{
		for(unsigned int frame= 0; frame < frames; ++frame)
		{
			float abs_in = std::abs(in[frame]);

			if(abs_in < threshold)
				in[frame] *= 2;
			else if(abs_in >= threshold && abs_in < 2*threshold)
			{
				float ret = (3 - pow(2 - abs_in * 3, 2)) / 3.0;
				in[frame] = (in[frame] > 0) ? ret : -ret;
			}
			else
				in[frame] = (in[frame] > 0) ? 1 : -1;
		}
		return in;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			threshold = v;
	}

	std::string name() override
	{
		return "Overdrive";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Thresh";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return threshold;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_PEDAL;
	}

private:
	float threshold;
};

PLUGIN_API
