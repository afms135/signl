#include "effect.h"

class plugin : public effect
{
public:
	plugin(unsigned int rate) : index(0), noofsamples(12012), period(0.5)
	{
	}

	float operator()(float in) override
	{
		if(index++ > noofsamples)
		{
			index %= noofsamples * 2; 
			return 0.0;
		}
		
		return in;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
		{	
			period = v;
			noofsamples = (period * 24000) + 12;
		}

	}

	std::string name() override
	{
		return "Tremolo";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Period";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return period;
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
};

PLUGIN_API
