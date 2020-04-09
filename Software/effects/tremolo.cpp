#include "effect.h"

class plugin : public effect
{
public:
	plugin(unsigned int rate) : index(0)
	{
	}

	float operator()(float in) override
	{
		if(index++ > 24000)
		{
			index %= 48000; 
			return 0.0;
		}
		
		return in;
	}

	void paramset(param p, float v) override
	{

	}

	std::string name() override
	{
		return "Tremolo";
	}

	std::string paramname(param p) override
	{
		return "";
	}

	float paramval(param p) override
	{
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_AMP;
	}

private:

	unsigned int index;
};

PLUGIN_API
