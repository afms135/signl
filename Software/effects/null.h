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

	std::string name() override
	{
		return "Null";
	}

	std::string paramname(param p) override
	{
		return "";
	}
};

#endif /*NULL_H*/
