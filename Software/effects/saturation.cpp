#include "effect.h"
#include <cmath>

class plugin : public effect
{
public:
	plugin(unsigned int rate) : gain(2.4), gain_raw(0.2), drive(2.24), drive_raw(0.4), level(0.8)
	{
	}

	float* operator()(float* in, const unsigned int frames) override
	{
		for (unsigned int frame = 0; frame < frames; ++frame)
		{
			float abs_in = std::abs(in[frame]);

			in[frame] = (in[frame]*(abs_in + drive)/(pow(in[frame],2) + (drive-1)*abs_in + 1) ) * level;
		}
		return in;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
		{
			gain_raw = v;
			gain = (v*2)+2;
			drive = pow(drive_raw+1,gain);
		}
		else if(p == PARAM_B)
		{
			drive_raw = v;
			drive = pow(v+1,gain);
		}
		else if(p == PARAM_D)
			level = v;
	}

	std::string name() override
	{
		return "Saturation";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Gain";
		else if (p == PARAM_B)
			return "Drive";
		else if (p == PARAM_D)
			return "Level";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return gain_raw;
		else if(p == PARAM_B)
			return drive_raw;
		else if(p == PARAM_D)
			return level;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_TAPE;
	}

private:
	float gain;
	float gain_raw;
	float drive;
	float drive_raw;
	float level;
};

PLUGIN_API
