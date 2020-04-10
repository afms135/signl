#ifndef EFFECT_H
#define EFFECT_H
#include <string>

/**
 * \brief Abstract class representing a audio effect.
 *
 * An audio effect should inherit this base class and override all virtual methods.
 * The inherited class is also passed the sample rate in its constructor.
 *
 * Effects have four configurable parameters.
 *
 * Example of an amplifier effect:
 * \code
 * #include "effect.h"
 *
 * class plugin : public effect
 * {
 * public:
 * 	plugin(unsigned int rate) : gain(1)
 * 	{
 * 	}
 *
 * 	float operator()(float in) override
 * 	{
 * 		float out = in * gain;
 *
 * 		//Clip
 * 		if(out > 1.0f)
 * 			out = 1.0f;
 * 		if(out < -1.0f)
 * 			out = -1.0f;
 *
 * 		return out;
 * 	}
 *
 * 	void paramset(param p, float v) override
 * 	{
 * 		if(p == PARAM_A)
 * 			gain = v;
 * 	}
 *
 * 	std::string name() override
 * 	{
 * 		return "Amplifier";
 * 	}
 *
 * 	std::string paramname(param p) override
 * 	{
 * 		if(p == PARAM_A)
 * 			return "Gain";
 * 		return "";
 * 	}
 *
 * 	float paramval(param p) override
 * 	{
 * 		if(p == PARAM_A)
 * 			return gain;
 * 		return -1;
 * 	}
 *
 * 	gui_icon icon() override
 * 	{
 * 		return ICON_AMP;
 * 	}
 *
 * private:
 * 	float gain;
 * };
 * \endcode
 */
struct effect
{
	///Parameter types.
	enum param
	{
		PARAM_A, ///<Parameter A
		PARAM_B, ///<Parameter B
		PARAM_C, ///<Parameter C
		PARAM_D  ///<Parameter D
	};

	///Indices of sprites defined in \c assets\sprites.cpp.
	enum gui_icon
	{
		ICON_NONE      = 0,  ///<Sprite of an empty line.
		ICON_EMPTY_BOX = 1,  ///<Sprite of an empty box.
		ICON_AMP       = 2,  ///<Sprite of a guitar amplifier.
		ICON_PEDAL     = 3,  ///<Sprite of a guitar pedal.
		ICON_FADER     = 4,  ///<Sprite of a box with four faders.
		ICON_VUMETER   = 5,  ///<Sprite of a VU meter.
		ICON_TAPE      = 6,  ///<Sprite of a reel-to-reel tape machine.
		ICON_VINYL     = 7,  ///<Sprite of a record player.
		ICON_MUSIC     = 8,  ///<Sprite of a box with two notes.
		ICON_RADIO     = 9,  ///<Sprite of a radio.
		ICON_SPEAKER   = 10, ///<Sprite of a speaker.
		ICON_WOBBLE    = 11, ///<Sprite of a wobble pedal.
		ICON_DELAY     = 12  ///<Sprite of a delay pedal.
	};

	/**
	 * \brief Destructor.
	 *
	 * Inherited class should clean up any resources here.
	 */
	virtual ~effect() {}

	/**
	 * \brief Process an audio sample.
	 *
	 * This function processes an single audio sample.
	 *
	 * \warning This function is called from a realtime priority thread,
	 * avoid blocking/long running function calls.
	 *
	 * \param in Audio sample to process.
	 * \retval float Processed audio sample.
	 */
	virtual float operator()(float in) = 0;

	/**
	 * \brief Set a effect parameter.
	 *
	 * Sets one of the four effect parameters.
	 *
	 * \param p Parameter to set.
	 * \param v Value to set parameter (between 0.0 and 1.0).
	 */
	virtual void paramset(param p, float v) = 0;

	/**
	 * \brief Effect name.
	 *
	 * Returns the name of the effect to be displayed on the GUI when effect
	 * is selected.
	 *
	 * \retval std::string String containing the effect name.
	 */
	virtual std::string name() = 0;

	/**
	 * \brief Name of parameter.
	 *
	 * Return the name of one of the four parameters to be displayed on the GUI
	 * when effect is selected.
	 *
	 * \param p Parameter to return name for.
	 * \retval std::string String containing the parameter name.
	 */
	virtual std::string paramname(param p) = 0;

	/**
	 * \brief Get an effect parameter value.
	 *
	 * Returns the value of one of the four effect parameters.
	 *
	 * \note Should return the same value set in #paramset().
	 *
	 * \param p Parameter to return value for.
	 * \retval float Parameter value (between 0.0 and 1.0).
	 */
	virtual float paramval(param p) = 0;

	/**
	 * \brief Get effect icon.
	 *
	 * Returns a reference to an icon to represent effect on the GUI.
	 *
	 * \retval gui_icon Icon to display.
	 */
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
		return "";
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

///Type definition of plugin create/destroy functions
typedef effect *(*plugin_ctor_t)(unsigned int);
typedef void (*plugin_dtor_t)(effect*);

///Macro used to automatically define the functions required for a dynamicaly
///loaded plugin.
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
