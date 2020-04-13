#include "effect.h"

class plugin : public effect
{
public:
	plugin(unsigned int rate) : gain(1)
	{
	}

	float process(float in) override
	{
		float out = in * gain;

		//Clip
		if(out > 1.0f)
			out = 1.0f;
		if(out < -1.0f)
			out = -1.0f;

		return out;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			gain = v;
	}

	std::string name() override
	{
		return "Amplifier";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Gain";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return gain;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_AMP;
	}

private:
	float gain;
};

PLUGIN_API
