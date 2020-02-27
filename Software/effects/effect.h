#ifndef EFFECT_H
#define EFFECT_H
#include <string>

struct effect
{
	enum param
	{
		PARAM_A,
		PARAM_B,
		PARAM_C,
		PARAM_D
	};

	virtual ~effect() {}
	virtual float operator()(float in) = 0;
	virtual void paramset(param p, float v) = 0;
	virtual std::string name() = 0;
};

#endif /*EFFECT_H*/
