#include "effect.h"
#include <cmath>
#include <time.h>

class plugin : public effect
{
public:
	plugin(unsigned int rate) :
	noise(0.05),
	scratches(0.5),
	filter(0.5),
	drywet(1.0)
	{
		srand(time(NULL));
	}

	float operator()(float in) override
	{
		float noise_fx = ((float)rand()/RAND_MAX)/2 - 0.25;
		return (in*(1-noise)) + (noise_fx*noise);
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			noise = v/4;
		else if(p == PARAM_B)
			scratches = v;
		else if(p == PARAM_C)
			filter = v;
		else if(p == PARAM_D)
			drywet = v;
	}

	std::string name() override
	{
		return "Vinyl";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Noise";
		else if(p == PARAM_B)
			return "Scratches";
		else if(p == PARAM_C)
			return "Filter";
		else if(p == PARAM_D)
			return "Dry-Wet";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return noise*4;
		else if(p == PARAM_B)
			return scratches;
		else if(p == PARAM_C)
			return filter;
		else if(p == PARAM_D)
			return drywet;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_VINYL;
	}

private:
	float noise;
	float scratches;
	float filter;
	float drywet;
};

PLUGIN_API
