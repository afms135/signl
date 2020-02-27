#ifndef AMP_H
#define AMP_H
#include "effect.h"

class amp : public effect
{
public:
	amp()
	{
		gain = 1;
	}

	float operator()(float in) override
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

private:
	float gain;
};

#endif /*AMP_H*/