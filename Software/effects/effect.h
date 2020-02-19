#ifndef EFFECT_H
#define EFFECT_H

struct effect
{
	virtual ~effect() {}
	virtual float operator()(float in) = 0;
};

#endif /*EFFECT_H*/
