#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin() : low(0.5), lowmid(0.5), highmid(0.5), high(0.5)
	{
	}

	float operator()(float in) override
	{
		return in;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			low = v;
		else if(p == PARAM_B)
			lowmid = v;
		else if(p == PARAM_C)
			highmid = v;
		else if(p == PARAM_D)
			high = v;
	}

	std::string name() override
	{
		return "EQ";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Low";
		else if(p == PARAM_B)
			return "Low-Mid";
		else if(p == PARAM_C)
			return "High-Mid";
		else if(p == PARAM_D)
			return "High";
		return "";
	}

	gui_icon icon() override
	{
		return ICON_FADER;
	}

private:
	float low;
	float lowmid;
    float highmid;
    float high;
};

PLUGIN_API
