#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	float operator()(float in) override
	{
		if(in >= 0 && in < 1.0/3.0)
			return 2 * in;
		else if(in >= 1.0/3.0 && in < 2.0/3.0)
			return (3 - pow(2 - 3 * in, 2)) / 3.0;
		else if(in >= 2.0/3.0 && in <= 1.0)
			return 1;
		else
			return in;
	}

	void paramset(param p, float v) override
	{
	}

	std::string name() override
	{
		return "Overdrive";
	}

	std::string paramname(param p) override
	{
		return "";
	}
};

PLUGIN_API
