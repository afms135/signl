#include "effect.h"

class plugin : public effect
{
public:
	plugin(unsigned int rate) : index(0), noofsamples(13200), period(0.5), cut(1), fade(0.1)
	{
	}

	float operator()(float in) override
	{
		float multiplier = 0.0;
		if(index < noofsamples * fade)
		{
			multiplier = (1-(1-cut)) / ((float)noofsamples * fade);
			multiplier = multiplier * (float)index;
			multiplier = multiplier + (1 - cut);
		} else if(index < noofsamples) 
			multiplier = 1;
		else if(index < (noofsamples * (1 + fade)))
		{
			multiplier = ((1-cut)-1) / ((float)noofsamples * fade);
			multiplier = multiplier * ((float)index - (float)noofsamples);
			multiplier = multiplier + 1;
		} else if(index < (2 * noofsamples))
			multiplier = 1-cut;
		
		index++;
		index %= 2 * noofsamples;
		return in * multiplier;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
		{	
			period = v;
			noofsamples = (period * 24000) + 2400;
		} else if(p == PARAM_B)
			cut = v;
		else if(p == PARAM_C)
			fade = v;


	}

	std::string name() override
	{
		return "Tremolo";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Period";
		else if(p == PARAM_B)
			return "Cut";
		else if(p == PARAM_C)
			return "Fade";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return period;
		else if(p == PARAM_B)
			return cut;
		else if(p == PARAM_C)
			return fade;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_PEDAL;
	}

private:

	unsigned int index;
	unsigned int noofsamples;
	float period;
	float cut;
	float fade;
};

PLUGIN_API
