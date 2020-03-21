#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin(unsigned int rate) : thresh(0.5), drive(0.2)
	{
	}

	float operator()(float in) override
	{
		float abs_in = std::abs(in);

		if (in < thresh)
		{
			return in;
		}
		else
		{
			float ret = (thresh + (abs_in - thresh) / (1 + pow( (abs_in - thresh ) / (1 - thresh ), drive*10.0)));
			return (in > 0) ? ret : -ret;
		}
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			thresh = v;
		else if(p == PARAM_B)
			drive = v;
	}

	std::string name() override
	{
		return "Tape Saturation";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Thresh";
		else if(p == PARAM_B)
			return "Drive";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return thresh;
		else if(p == PARAM_B)
			return drive;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_TAPE;
	}

private:
	float thresh;
	float drive;
};

PLUGIN_API
