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
};

#endif /*NULL_H*/
