#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin() : thresh(0.5), drive(2.0)
	{
	}

	float operator()(float in) override
	{
        float abs_in = abs(in);

        if (in < thresh)
        {
            return in;
        }
        else
        {
            float ret = (thresh + (abs_in-thresh) / (1+pow( (abs_in-thresh)/(1-thresh),drive )));
            return (in > 0) ? ret : -ret;
        }
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			thresh = 1.0-v;
        else if(p == PARAM_B)
            drive = v * 10.0;
	}

	std::string name() override
	{
		return "Tape Saturation";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Threshold";
        else if(p == PARAM_B)
        	return "Drive";
		return "";
	}

	gui_icon icon() override
	{
		return ICON_VUMETER;
	}

private:
	float thresh;
    float drive;
};

PLUGIN_API
