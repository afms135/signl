#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin() : thresh(1.0)
	{
	}

	float operator()(float in) override
	{
        int inv = 1;
        if (in < 0)
        {
            in = -1*in;
            inv = -1;
        }
        if (in < thresh)
        {
            return in*inv;
        }
        else
        {
            return (thresh + (in-thresh) / (1+pow( (in-thresh)/(1-thresh),2 )))*inv;
        }
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			thresh = 1.0-v;
	}

	std::string name() override
	{
		return "Saturation";
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
	float thresh;
};

PLUGIN_API
