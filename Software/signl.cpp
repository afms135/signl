#include "signl.h"
#include <iostream>
#include <stdexcept>
#include <cstring> //strerror()
#include <math.h>  //std::abs()

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
	effects("./effects"),
	effect_idx(0),
	effect_chain_idx{0,0,0,0,0},
	param_knobs{0.0,0.0,0.0,0.0},
	in_level(1.0),
	out_level(1.0),
	state(EFFECT_CHAIN)
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
	for(unsigned int i = 0; i < effects.size(); i++)
		std::cout << '\t' << effects(i, rate())->name() << std::endl;

	//Create blank effect chain
	for(int i = 0; i < NUM_EFFECTS; i++)
		effect_chain.push_back(effects(effects.EFFECT_NULL, rate()));

	running = 1;
	activate();
}

jack_client::sample_t sample_array[7][BUFFER_LENGTH] = {0};
unsigned int sample_array_idx[7] = {0};

jack_client::sample_t signl::process(sample_t in)
{
	unsigned int idx = 0;
	in *= in_level;
	sample_array[idx][sample_array_idx[idx]++] = in;
	sample_array_idx[idx] %= BUFFER_LENGTH;
	idx++;

	for(const auto &e : effect_chain)
	{
		//Process sample through effect number idx
		in = (*e)(in);
		//Add processed sample to sample_array[idx] at point sample_array_idx[idx]
		sample_array[idx][sample_array_idx[idx]++] = in;
		//Loop to start of sample_array if sample_array_idx has reached end
		sample_array_idx[idx] %= BUFFER_LENGTH;
		idx++;
	}

	float out = in * out_level;
	sample_array[idx][sample_array_idx[idx]++] = out;
	sample_array_idx[idx] %= BUFFER_LENGTH;
	return out;
}

void signl::start()
{
	std::cout << "Starting..." << std::endl;
	while(running)
	{
		if(state == EFFECT_CHAIN)
		{
			//Change state
			if(joy_push)
			{
				state = LEVEL_ADJ;
			}

			//Parameter input
			float param_in[4];
			param_in[0] = param(adc::CH0);
			param_in[1] = param(adc::CH1);
			param_in[2] = param(adc::CH2);
			param_in[3] = param(adc::CH3);

			for(unsigned int i = 0; i < 4; ++i)
			{
				if(std::abs(param_in[i] - param_knobs[i]) > 0.01)
				{
					param_knobs[i] = param_in[i];
					effect_chain[effect_idx]->paramset(static_cast<effect::param>(i),param_in[i]);
				}
			}

			//Joystick input
			if(joy_up)
			{
				effect_chain_idx[effect_idx]--;
				if(effect_chain_idx[effect_idx] >= effects.size())
					effect_chain_idx[effect_idx] = effects.size() - 1;
				effect_chain[effect_idx] = effects(effect_chain_idx[effect_idx], rate());
			}
			if(joy_down)
			{
				effect_chain_idx[effect_idx]++;
				effect_chain_idx[effect_idx] %= effects.size();
				effect_chain[effect_idx] = effects(effect_chain_idx[effect_idx], rate());
			}
			if(joy_left)
			{
				effect_idx--;
				if (effect_idx >= 5)
					effect_idx = 4;
			}
			if(joy_right)
			{
				effect_idx++;
				effect_idx %= 5;
			}

			//Display update
			display.clear();
			display.signl_view(effect_chain);
			display.param_view(effect_chain,effect_idx);
			display.flip();
		}
		else if (state == LEVEL_ADJ)
		{
			//State change
			if(joy_push)
			{
				state = EFFECT_CHAIN;
			}

			//Parameter input
			float param_in[4];
			param_in[0] = param(adc::CH0);
			param_in[1] = param(adc::CH1);
			param_in[2] = param(adc::CH2);
			param_in[3] = param(adc::CH3);

			for(unsigned int i = 0; i < 4; ++i)
			{
				if(std::abs(param_in[i] - param_knobs[i]) > 0.01)
				{
					param_knobs[i] = param_in[i];
					if (i == 0)
					{
						in_level = param_in[i];
					}
					else if(i == 3)
					{
						out_level = param_in[i];
					}
				}
			}

			//Display update
			display.clear();
			display.signl_view(effect_chain);
			display.level_view(in_level,out_level,sample_array);
			display.flip();
		}
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
