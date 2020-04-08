#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin(unsigned int rate)
	{
	}

	float operator()(float in) override
	{
		return in;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			threshold = v;
	}

	std::string name() override
	{
		return "Vinyl";
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
		return ICON_VINYL;
	}

private:
	float threshold;
};

PLUGIN_API
