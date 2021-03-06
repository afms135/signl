#include "signl.h"
#include <iostream>
#include <stdexcept>
#include <cstring> //strerror()
#include <cmath>   //std::abs()

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
//Flag to shutdown software
volatile sig_atomic_t signl::running = 0;

signl::signl() :
	//Base class
	jack_client("signl"),
	//Hardware
	display(SPI_LCD, GPIO, LCD_A0, LCD_RES),
	param(SPI_ADC),
	joy_up(GPIO, JOY_UP, false, DEBOUNCE_TIME, "JOY_UP"),
	joy_down(GPIO, JOY_DOWN, false, DEBOUNCE_TIME, "JOY_DOWN"),
	joy_left(GPIO, JOY_LEFT, false, DEBOUNCE_TIME, "JOY_LEFT"),
	joy_right(GPIO, JOY_RIGHT, false, DEBOUNCE_TIME, "JOY_RIGHT"),
	joy_push(GPIO, JOY_PUSH, false, DEBOUNCE_TIME, "JOY_PUSH"),
	//Effect manager
	effects("./effects"),
	//Effect selection index
	effect_idx(0),
	//Array of previous samples
	sample_array(),
	sample_array_idx(0),
	//FFT buffers
	tuner_array(),
	tuner_array_idx(0),
	fft_re(audiofft::AudioFFT::ComplexSize(gui::TUNER_BUFFER_LENGTH)),
	fft_im(audiofft::AudioFFT::ComplexSize(gui::TUNER_BUFFER_LENGTH)),
	//Parameter values
	param_val{0.0, 0.0, 0.0, 0.0},
	param_updated{false, false, false, false},
	//Input output gain
	in_level(1.0),
	out_level(1.0),
	//UI state
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
	for(auto &e : effects.list(rate()))
		std::cout << '\t' << e->name() << std::endl;

	//Create blank effect chain
	for(unsigned int i = 0; i < NUM_EFFECTS; i++)
	{
		effect_list lst(effects.list(rate()));
		effect_chain.push_back(std::move(lst));
	}

	//Initialise gaussian window
	for(unsigned int i = 0; i < gui::TUNER_BUFFER_LENGTH; ++i)
	{
		gauss.push_back(exp(-0.5*pow(0.4f*(i- ((gui::TUNER_BUFFER_LENGTH/2.0f)-1))/((gui::TUNER_BUFFER_LENGTH/2.0f)-1) ,2)));
	}

	running = 1;
	activate();
}

jack_client::sample_t signl::process(sample_t in)
{
	//Input gain, save for level display
	in *= in_level;
	sample_array[0][sample_array_idx] = in;

	//Store the input buffer for the tuner
	tuner_array[tuner_array_idx] = in;
	tuner_array_idx = (tuner_array_idx + 1) % gui::TUNER_BUFFER_LENGTH;

	//Process sample through effect chain, save intermediate results for level
	for(unsigned int i = 0; i < NUM_EFFECTS; i++)
	{
		in = effect_chain[i]()->process(in);
		sample_array[i+1][sample_array_idx] = in;
	}

	//Output gain, save for level display
	float out = in * out_level;
	sample_array[6][sample_array_idx] = out;

	//Loop array index (ring buffer)
	sample_array_idx = (sample_array_idx + 1) % gui::BUFFER_LENGTH;

	return out;
}

void signl::param_update()
{
	//For each parameter check if it has moved enough
	for(unsigned int i = 0; i < NUM_PARAMS; ++i)
	{
		//Read ADC
		float in = param(static_cast<adc::channel>(i));

		if(std::abs(in - param_val[i]) > 0.01)
		{
			//Save new value
			param_val[i] = in;
			param_updated[i] = true;
		}
	}
}

void signl::start()
{
	std::cout << "Starting..." << std::endl;
	while(running)
	{
		//Update parameters
		param_update();

		//User interface loop
		display.clear();

		//GUI states
		if(state == EFFECT_CHAIN)
		{
			//Change state
			if(joy_push)
				state = LEVEL_ADJ;

			//Update effect parameters
			for(unsigned int i = 0; i < NUM_PARAMS; i++)
			{
				if(param_updated[i])
					effect_chain[effect_idx]()->paramset(static_cast<effect::param>(i), param_val[i]);
			}

			//Joystick input
			if(joy_up)
				effect_chain[effect_idx]--;
			if(joy_down)
				effect_chain[effect_idx]++;
			if(joy_left)
			{
				effect_idx--;
				if (effect_idx >= NUM_EFFECTS)
					effect_idx = NUM_EFFECTS-1;
			}
			if(joy_right)
			{
				effect_idx++;
				effect_idx %= NUM_EFFECTS;
			}

			//Show parameter modify display
			display.param_view(effect_chain,effect_idx);
		}
		else if (state == LEVEL_ADJ)
		{
			//State change
			if(joy_push)
				state = TUNER;

			//Update input/output levels
			if(param_updated[0])
				in_level = 4*pow(param_val[0],2);
			if(param_updated[3])
				out_level = 4*pow(param_val[3],2);

			//Show sound level display
			display.level_view(in_level,out_level,sample_array);
		}
		else if (state == TUNER)
		{
			//State change
			if(joy_push)
				state = EFFECT_CHAIN;

			//Gaussian window the current tuner_array
			for(unsigned int i = 0; i < gui::TUNER_BUFFER_LENGTH; ++i)
				tuner_array[(tuner_array_idx + i) % gui::TUNER_BUFFER_LENGTH] *= gauss[i];

			//FFT the input sample buffer
			fft.init(gui::TUNER_BUFFER_LENGTH);
			fft.fft(tuner_array, fft_re.data(), fft_im.data());

			// find abs (store in re)
			for(unsigned int i = 0; i < fft_re.size(); ++i)
				fft_re[i] = sqrt(pow(fft_re[i],2)+pow(fft_im[i],2));

			// Show the tuner view
			display.tuner_view(fft_re.data());
		}

		//Reset param update flags, update display
		for(unsigned int i = 0; i < NUM_PARAMS; i++)
			param_updated[i] = false;
		display.signl_view(effect_chain);
		display.flip();
	}
	deactivate();
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
