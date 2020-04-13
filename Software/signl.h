#ifndef SIGNL_H
#define SIGNL_H
#include "jack.h"
#include "gui.h"
#include "effect_manager.h"
#include "hw/adc.h"
#include "hw/debounce.h"
#include <memory>
#include <vector>
#include <signal.h>

class signl : jack_client
{
public:
	static const unsigned int NUM_EFFECTS = 5;

	signl();
	sample_t process(sample_t in);
	void shutdown();
	void start();

private:
	gui display;
	adc param;
	debounce joy_up;
	debounce joy_down;
	debounce joy_left;
	debounce joy_right;
	debounce joy_push;
	effect_manager effects;
	std::vector<std::unique_ptr<effect, plugin_dtor_t>> effect_chain;
	static void sigterm_handler(int sig);
	static volatile sig_atomic_t running;

	unsigned int effect_idx;
	unsigned int effect_chain_idx[NUM_EFFECTS];
	float param_knobs[4];

	jack_client::sample_t sample_array[7][gui::BUFFER_LENGTH];
	size_t sample_array_idx;

	float in_level;
	float out_level;
	enum disp_state
	{
		EFFECT_CHAIN,
		LEVEL_ADJ
	};
	disp_state state;
};

#endif /*SIGNL_H*/
