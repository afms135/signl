#include "effect.h"
#include <cmath>
#include <time.h>
#include "./vinyl_clicks.h"

class plugin : public effect
{
public:
	plugin(unsigned int rate) :
	noise(0.05),
	scratches(0.5),
	filter(0.5),
	drywet(1.0),
	popping(0),
	click_idx(0),
	click_arr_idx(0),
	xn1(0.0),
	xn2(0.0),
	yn1(0.0),
	yn2(0.0)
	{
		// Initialise the random number generator for the noise
		srand(time(NULL));
		b0 = 0.03780475;
		b1 = 0.0;
		b2 = -0.03780475;
		a0 = 1.0;
		a1 = -1.91779609;
		a2 = 0.92439049;

	}

	float operator()(float in) override
	{
		float noise_fx = 0.0;
		// Are we currently making a click sound?
		if (!popping)
		{
			// If not, make white noise:
			noise_fx = ((float)rand()/RAND_MAX)/4 - 0.125;
			// And randomly decide to make a click
			if(fabs(noise_fx) < 0.00001*scratches)
				popping = 1;
			//scale the white noise
			noise_fx *= noise;
		}
		else
		// If we are currently making a click
		{
			// play the next sample in the current click buffer
			noise_fx = click[click_arr_idx][click_idx++];
			// If we have reached the end of the current click
			if(click_idx == click[click_arr_idx].size())
			{
				// Go back to making white noise
				popping = 0;
				// Reset the click buffer index
				click_idx = 0;
				// move the click vector index to the next click buffer
				click_arr_idx++;
				click_arr_idx %= click.size();
			}
		}
		float filtered_in = 0.0;
		filtered_in = ((b0*in) + (b1*xn1) + (b2*xn2) - (a1*yn1) - (a2*yn2))/a0;
		xn2 = xn1;
		xn1 = in;
		yn2 = yn1;
		yn1 = filtered_in;

		return (filtered_in*(1-noise)) + noise_fx;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			noise = v/4;
		else if(p == PARAM_B)
			scratches = v;
		else if(p == PARAM_C)
		{
			filter = v;
		}
		else if(p == PARAM_D)
			drywet = v;
	}

	std::string name() override
	{
		return "Vinyl";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Noise";
		else if(p == PARAM_B)
			return "Scratch";
		else if(p == PARAM_C)
			return "Filter";
		else if(p == PARAM_D)
			return "Dry-Wet";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return noise*4;
		else if(p == PARAM_B)
			return scratches;
		else if(p == PARAM_C)
			return filter;
		else if(p == PARAM_D)
			return drywet;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_VINYL;
	}

private:
	float noise;
	float scratches;
	float filter;
	float drywet;

	bool popping;
	unsigned int click_idx;
	unsigned int click_arr_idx;

	float b0,b1,b2,a0,a1,a2;
	float xn1;
	float xn2;
	float yn1;
	float yn2;
};

PLUGIN_API
