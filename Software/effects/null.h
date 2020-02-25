#ifndef NULL_H
#define NULL_H
#include "effect.h"

class null : public effect
{
public:
	float operator()(float in) override
	{
		return in;
	}

	void paramset(param p, float v) override
	{
	}
};

#endif /*NULL_H*/
