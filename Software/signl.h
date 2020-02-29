#ifndef SIGNL_H
#define SIGNL_H
#include "jack.h"
#include "effect_manager.h"
#include "hw/lcd.h"
#include "hw/debounce.h"
#include "hw/adc.h"
#include <memory>
#include <vector>
#include <signal.h>

class signl : jack_client
{
public:
	signl();
	sample_t process(sample_t in);
	void shutdown();
	void start();

private:
	std::vector<std::unique_ptr<effect>> effect_chain;
	lcd display;
	adc param;
	debounce joy_up;
	debounce joy_down;
	debounce joy_left;
	debounce joy_right;
	debounce joy_push;
	effect_manager effects;
	static void sigterm_handler(int sig);
	static volatile sig_atomic_t running;
};

#endif /*SIGNL_H*/
