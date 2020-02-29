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
	virtual std::string paramname(param p) = 0;
};

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

//Type definition of plugin create/destroy functions
typedef effect *(*plugin_ctor_t)(void);
typedef void (*plugin_dtor_t)(effect*);

#endif /*EFFECT_H*/
