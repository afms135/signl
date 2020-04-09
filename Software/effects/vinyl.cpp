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
		// Initialiseth filter coefficients
		calc_coeffs();
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
//		float filtered_in = 0.0;
//		filtered_in = ((filter_coeffs[0]*in) + (filter_coeffs[1]*xn1) + (filter_coeffs[2]*xn2) - (filter_coeffs[3]*yn1) - (filter_coeffs[4]*yn2))/filter_coeffs[5];
//		xn2 = xn1;
//		xn1 = in;
//		yn2 = yn1;
//		yn1 = filtered_in;

		return (in*(1-noise)) + noise_fx;
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
			calc_coeffs();
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
	void calc_coeffs()
	{
		filter_coeffs[1] = 0.0;
		filter_coeffs[3] = 1.0;
		// Estimate based on band pass from 200-400 for filter=0.
		//  up to 1-4000 for filter=1.
		filter_coeffs[0] = 0.13485961*(pow(filter,3)) -0.09734503*(pow(filter,2)) +0.05862078*(filter) +0.00509859;
		filter_coeffs[2] = -0.13485961*(pow(filter,3)) +0.09734503*(pow(filter,2)) -0.05862078*(filter) -0.00509859;
		filter_coeffs[4] = 0.26912073*(pow(filter,3)) -0.19299669*(pow(filter,2)) +0.11578005*(filter) -1.98941226;
		filter_coeffs[5] = -0.26971923*(pow(filter,3)) +0.19469006*(pow(filter,2)) -0.11724157*(filter) +0.98980282;
	}

	float noise;
	float scratches;
	float filter;
	float drywet;

	bool popping;
	unsigned int click_idx;
	unsigned int click_arr_idx;

	float filter_coeffs[6];
	float xn1;
	float xn2;
	float yn1;
	float yn2;
};

PLUGIN_API
