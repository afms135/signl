#include "effect.h"

class plugin : public effect
{
public:
	plugin(unsigned int rate) : index(0), noofsamples(13200), period(0.5), cut(1)
	{
	}

	float operator()(float in) override
	{
		if(index++ > noofsamples)
		{
			index %= noofsamples * 2; 
			return in * (1-cut);
		}
		
		return in;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
		{	
			period = v;
			noofsamples = (period * 24000) + 2400;
		} else if(p == PARAM_B)
			cut = v;

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
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return period;
		else if(p == PARAM_B)
			return cut;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_AMP;
	}

private:

	unsigned int index;
	unsigned int noofsamples;
	float period;
	float cut;
};

PLUGIN_API
