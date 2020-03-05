#include "signl.h"
#include <iostream>
#include <stdexcept>
#include <cstring> //strerror()

constexpr auto NUM_EFFECTS = 5;
//Device names
const std::string GPIO = "/dev/gpiochip0";
const std::string SPI_ADC = "/dev/spidev0.0";
const std::string SPI_LCD = "/dev/spidev0.1";
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
	display(SPI_LCD, GPIO, LCD_A0, LCD_RES),
	param(SPI_ADC),
	joy_up(GPIO, JOY_UP, false, DEBOUNCE_TIME, "JOY_UP"),
	joy_down(GPIO, JOY_DOWN, false, DEBOUNCE_TIME, "JOY_DOWN"),
	joy_left(GPIO, JOY_LEFT, false, DEBOUNCE_TIME, "JOY_LEFT"),
	joy_right(GPIO, JOY_RIGHT, false, DEBOUNCE_TIME, "JOY_RIGHT"),
	joy_push(GPIO, JOY_PUSH, false, DEBOUNCE_TIME, "JOY_PUSH"),
	effects("./effects")
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

	//Print list of loaded plugins
	std::cout << "Loaded plugins:" << std::endl;
	for(int i = 0; i < effects.size(); i++)
		std::cout << '\t' << effects(i)->name() << std::endl;

	//Create blank effect chain
	for(int i = 0; i < NUM_EFFECTS; i++)
		effect_chain.push_back(effects(effects.EFFECT_NULL));

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
		//Parameter input
		float A = param(adc::CH0);
		float B = param(adc::CH1);
		float C = param(adc::CH2);
		float D = param(adc::CH3);

		//Joystick input
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

		//Display update
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
