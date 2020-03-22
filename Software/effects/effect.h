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

	enum gui_icon
	{
		ICON_NONE    = 0,
		ICON_AMP     = 1,
		ICON_PEDAL   = 2,
		ICON_FADER   = 3,
		ICON_VUMETER = 4,
		ICON_TAPE    = 5,
		ICON_VINYL	 = 6
	};

	virtual ~effect() {}
	virtual float operator()(float in) = 0;
	virtual void paramset(param p, float v) = 0;
	virtual std::string name() = 0;
	virtual std::string paramname(param p) = 0;
	virtual float paramval(param p) = 0;
	virtual gui_icon icon() = 0;
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

	float paramval(param p) override
	{
		return 0;
	}

	gui_icon icon() override
	{
		return ICON_NONE;
	}
};

//Type definition of plugin create/destroy functions
typedef effect *(*plugin_ctor_t)(unsigned int);
typedef void (*plugin_dtor_t)(effect*);

#define PLUGIN_API                       \
extern "C"                               \
{                                        \
effect *plugin_create(unsigned int rate) \
{                                        \
return new plugin(rate);                 \
}                                        \
                                         \
void plugin_destroy(effect *e)           \
{                                        \
delete e;                                \
}                                        \
}

#endif /*EFFECT_H*/
