#include "effect.h"
#include <cmath>

// TODO: Make a class for a 2nd order IIR filter.
//	 Init four of those classes (low, lowmid, highmid, high)
//	 	with freqs, and qs in the init
//	 Then send params as the gains for each
//	 In process, in goes via all four in parallel (outputs summed)
//	 Each class takes care of its own coeffs and x/yn#s

class plugin : public effect
{
public:
	plugin(unsigned int rate) : rate(rate), low(0.5), lowmid(0.5), highmid(0.5), high(0.5)
	// Filter params produced by scipy.signal.iirfilter
	{
	b0[0] = 9.50600294e-05;
	b1[0] = 1.90120059e-04;
	b2[0] = 9.50600294e-05;
	a0[0] = 1.0;
	a1[0] = -1.97223373;
	a2[0] = 0.972613969;

	b0[1] = 0.00972234;
	b1[1] = 0.0;
	b2[1] = -0.00972234;
	a0[1] = 1.0;
	a1[1] = -1.97979178;
	a2[1] = 0.98055532;

	b0[2] = 0.15151941;
	b1[2] = 0.0;
	b2[2] = -0.15151941;
	a0[2] = 1.0;
	a1[2] = -1.68375564;
	a2[2] = 0.69696118;

	b0[3] = 0.75707638;
	b1[3] = -1.51415275;
	b2[3] = 0.75707638;
	a0[3] = 1.0;
	a1[3] = -1.45424359;
	a2[3] = 0.57406192;

	}

	float operator()(float in) override
	{
		float out = 0;
		float filtered[4] = {0};
		for(unsigned int i = 0; i < 4; ++i)
		{
			filtered[i] = ((b0[i]*in) + (b1[i]*xn1[i]) + (b2[i]*xn2[i])
					 - (a1[i]*yn1[i]) - (a2[i]*yn2[i]))/a0[i];

			xn2[i] = xn1[i];
			xn1[i] = in;
			yn2[i] = yn1[i];
			yn1[i] = filtered[i];
			filtered[i] *= level[i];

			out += filtered[i];
		}
		return out;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
		{
			low = v;
			level[0] = 4*pow(low,2);   // Allow gain boost of ~+12dB
		}
		else if(p == PARAM_B)
		{
			lowmid = v;
			level[1] = 4*pow(lowmid,2);
		}
		else if(p == PARAM_C)
		{
			highmid = v;
			level[2] = 4*pow(highmid,2);
		}
		else if(p == PARAM_D)
		{
			high = v;
			level[3] = 4*pow(high,2);
		}
	}

	std::string name() override
	{
		return "EQ";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Low";
		else if(p == PARAM_B)
			return "Low-Mid";
		else if(p == PARAM_C)
			return "High-Mid";
		else if(p == PARAM_D)
			return "High";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return low;
		else if(p == PARAM_B)
			return lowmid;
		else if(p == PARAM_C)
			return highmid;
		else if(p == PARAM_D)
			return high;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_FADER;
	}

private:
	unsigned int rate;

	float low;
	float lowmid;
	float highmid;
	float high;
	float level[4] = {1,1,1,1};

	float xn1[4] = {0};
	float xn2[4] = {0};
	float yn1[4] = {0};
	float yn2[4] = {0};

	float b0[4],b1[4],b2[4],a0[4],a1[4],a2[4];
};

PLUGIN_API
