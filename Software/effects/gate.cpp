#include "effect.h"
#include <cmath>

// TODO: Add attack and release functionality

class plugin : public effect
{
public:
	plugin(unsigned int rate) :
		rate(rate),
		thresh(0.1),
		attack(2.0),
		attack_raw(0.0),
		release(10.0),
		release_raw(0.0),
		reduction(1.0),
		hold(rate * 30 / 1000) // 30ms in samples
	{
	}

	float operator()(float in) override
	{
		float abs_in = std::abs(in);

		// Gate state
		if (state == 0)
		{
			return (abs_in > thresh) ? enterAttackState(in) : gateState(in);
		}

		// Attack state
		else if (state == 1)
		{
			time_under(abs_in);

			if (samples_under_threshold >= hold)
			{
				return enterReleaseState(in);
			}
			else
			{
				return (index >= attack) ? enterHoldState(in) : attackState(in);
			}
		}

		// Hold state
		else if (state == 2)
		{
			time_under(abs_in);

			return (samples_under_threshold >= hold) ? enterReleaseState(in) : holdState(in);
		}

		// Release state
		else if (state == 3)
		{
			if (abs_in > thresh)
			{
				return enterAttackState(in);
			}
			else
			{
				return (index >= release) ? enterGateState(in) : releaseState(in);
			}
		}

		// Shouldn't ever get here
		return in;
	}

	void paramset(param p, float v) override
	{
		if(p == PARAM_A)
			thresh = v;
		else if(p == PARAM_B)
		{
			attack_raw = v;
			attack = pow(100,v) - 1; // in milliseconds
			attack = rate * attack / 1000; // in samples
		}
		else if(p == PARAM_C)
		{
			release_raw = v;
			release = pow(1000,v) - 1; // in milliseconds
			release = rate * release / 1000; // in samples
		}
		else if(p == PARAM_D)
			reduction = v;
	}

	std::string name() override
	{
		return "Noise Gate";
	}

	std::string paramname(param p) override
	{
		if(p == PARAM_A)
			return "Thresh";
		else if(p == PARAM_B)
			return "Attack";
		else if(p == PARAM_C)
			return "Release";
		else if(p == PARAM_D)
			return "Amount";
		return "";
	}

	float paramval(param p) override
	{
		if(p == PARAM_A)
			return thresh;
		else if(p == PARAM_B)
			return attack_raw;
		else if(p == PARAM_C)
			return release_raw;
		else if(p == PARAM_D)
			return reduction;
		return -1;
	}

	gui_icon icon() override
	{
		return ICON_VUMETER;
	}

private:
	void time_under(float in)
	{
		if (in < thresh)
			samples_under_threshold++;
		else
			samples_under_threshold = 0;
	}

	float gateState(float in)
	{
		return in * (1-reduction);
	}

	float attackState(float in)
	{
		index++;
		return in * ((reduction * index / attack) + (1 - reduction));
	}

	float holdState(float in)
	{
		return in;
	}

	float releaseState(float in)
	{
		index++;
		return in * (1 - (reduction * index / release));
	}

	float enterGateState(float in)
	{
		state = 0;
		return gateState(in);
	}

	float enterAttackState(float in)
	{
		// from gate state
		if (state == 0)
		{
			index = 0;
		}
		// from release state
		else if (state == 3)
		{
			index = attack * (1 - (index / release));
		}

		samples_under_threshold = 0;
		state = 1;
		return attackState(in);
	}

	float enterHoldState(float in)
	{
		state = 2;
		return holdState(in);
	}

	float enterReleaseState(float in)
	{
		// from attack state
		if (state == 1)
		{
			index = release * (1 - (index / attack));
		}
		// from hold state
		else if (state == 2)
		{
			index = 0;
		}

		state = 3;
		return releaseState(in);
	}

	unsigned int rate;
	float thresh;    // from 0. to 1. (linear)
	float attack;    // from 0. to 100. (in milliseconds) (log)
	float attack_raw;
	float release;   // from 0. to 1000. (in milliseconds) (log)
	float release_raw;
	float reduction; // from 0. to 1. (linear)
	float hold;

	float samples_under_threshold = 0;
	float index = 0;
	float state = 0; // 0 = gate, 1 = attack, 2 = hold, 3 = release
};

PLUGIN_API
