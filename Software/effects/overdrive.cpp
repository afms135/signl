#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin(unsigned int rate) : threshold(1.0/3.0)
	{
	}

	float operator()(float in) override
	{
		float abs_in = std::abs(in);

		if(abs_in < threshold)
			return 2 * in;
		else if(abs_in >= threshold && abs_in < 2*threshold)
		{
			float ret = (3 - pow(2 - abs_in * 3, 2)) / 3.0;
			return (in > 0) ? ret : -ret;
		}
		else
			return (in > 0) ? 1 : -1;
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
			return "Threshold";
		return "";
	}

	gui_icon icon() override
	{
		return ICON_PEDAL;
	}

private:
	float threshold;
};

PLUGIN_API
