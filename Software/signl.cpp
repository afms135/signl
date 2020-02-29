#include "signl.h"
#include "effects/null.h"
#include <iostream>
#include <stdexcept>
#include <cstring> //strerror()

constexpr auto NUM_EFFECTS = 5;
//Device names
const std::string GPIO = "/dev/gpiochip0";
const std::string SPI  = "/dev/spidev0.1";
//Pins
const auto LCD_A0    = 12;
const auto LCD_RES   = 13;
const auto JOY_UP    = 24;
const auto JOY_DOWN  = 26;
const auto JOY_LEFT  = 22;
const auto JOY_RIGHT = 25;
const auto JOY_PUSH  = 23;
const auto DEBOUNCE_TIME = 20;

volatile sig_atomic_t signl::running = 0;

signl::signl() :
	jack_client("signl"),
	effect_chain(NUM_EFFECTS),
	display(SPI, GPIO, LCD_A0, LCD_RES),
	joy_up(GPIO, JOY_UP, false, DEBOUNCE_TIME, "JOY_UP"),
	joy_down(GPIO, JOY_DOWN, false, DEBOUNCE_TIME, "JOY_DOWN"),
	joy_left(GPIO, JOY_LEFT, false, DEBOUNCE_TIME, "JOY_LEFT"),
	joy_right(GPIO, JOY_RIGHT, false, DEBOUNCE_TIME, "JOY_RIGHT"),
	joy_push(GPIO, JOY_PUSH, false, DEBOUNCE_TIME, "JOY_PUSH")
{
	//Register signal handlers
	struct sigaction s;
	s.sa_handler = sigterm_handler;
	s.sa_flags = SA_RESTART;
	sigemptyset(&s.sa_mask);
	if(sigaction(SIGTERM, &s, NULL))
		throw std::runtime_error("sigaction(): Could not register SIGTERM handler: " + std::string(strerror(errno)));
	if(sigaction(SIGINT, &s, NULL))
		throw std::runtime_error("sigaction(): Could not register SIGINT handler: " + std::string(strerror(errno)));

	//Create blank effect chain
	for(auto &e : effect_chain)
		e = std::unique_ptr<null>(new null());

	running = 1;
	activate();
}

jack_client::sample_t signl::process(sample_t in)
{
	for(const auto &e : effect_chain)
		in = (*e)(in);
    return in;
}

void signl::start()
{
	std::cout << "Starting..." << std::endl;
	while(running)
	{
		if(joy_up)
		{
		}
		if(joy_down)
		{
		}
		if(joy_left)
		{
		}
		if(joy_right)
		{
		}
		if(joy_push)
		{
		}

		display.clear();
		display.flip();
	}
	std::cout << "Stopping..." << std::endl;
}

void signl::shutdown()
{
	running = 0;
}

void signl::sigterm_handler(int sig)
{
	running = 0;
}
