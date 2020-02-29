#include "debounce.h"

debounce::debounce(std::string gpiochip, int pin, bool active, int time, std::string label) :
	gpioin(gpiochip, pin, label),
	last_val(!active),
	active(active),
	start_time(std::chrono::steady_clock::now()),
	debounce_time(20)
{
}

debounce::operator bool()
{
	//State changed
	bool cur_val = gpioin::operator bool();
	if(cur_val != last_val)
	{
		last_val = cur_val;

		//Detect edge
		if(cur_val == active)
			start_time = std::chrono::steady_clock::now();
		else
		{
			auto delta = std::chrono::steady_clock::now() - start_time;
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
			//Held long enough?
			if(ms > debounce_time)
				return true;
		}
	}
	return false;
}
