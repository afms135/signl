#ifndef DEBOUNCE_H
#define DEBOUNCE_H
#include "gpio.h"
#include <string>
#include <chrono>

class debounce : public gpioin
{
public:
	debounce(std::string gpiochip, int pin, bool active = true, int time = 20, std::string label = "");
	explicit operator bool();

private:
	bool last_val;
	const bool active;
	std::chrono::time_point<std::chrono::steady_clock> start_time;
	const std::chrono::milliseconds debounce_time;
};

#endif /*DEBOUNCE_H*/
