#ifndef SIGNL_H
#define SIGNL_H
#include "jack.h"
#include "gui.h"
#include "effect_manager.h"
#include "effect_list.h"
#include "hw/adc.h"
#include "hw/debounce.h"
#include <memory>
#include <vector>
#include <signal.h>
#include "effects/FFTConvolver/AudioFFT.h"

/**
 * \brief Main application class.
 *
 * This class contains the main application.
 *
 * The main loop is contained in the #start() function.
 *
 * Audio processing occurs in the #process() function in a seperate thread.
 */
class signl : jack_client
{
public:
	///Number of effects in the effect chain.
	static const unsigned int NUM_EFFECTS = 5;
	///Number of configurable parameters that each effect has.
	static const unsigned int NUM_PARAMS = 4;

	/**
	 * \brief Create an instance of the main program.
	 *
	 * Initialises class members, registers #sigterm_handler() with the
	 * \c SIGINT and \c SIGTERM signals, prints list of loaded effects to
	 * stdout, fills #effect_chain with the #null effect and calls #activate()
	 * to start the JACK callback.
	 *
	 * \exception std::runtime_error If setting the SIGTERM or SIGINT handler failed.
	 */
	signl();

	/**
	 * \brief JACK sample processing callback.
	 *
	 * Passes the input sample through the effect chain (#effect_chain),
	 * saves the intermediary samples in #sample_array and updates
	 * #sample_array_idx wrapping at gui::BUFFER_LENGTH forming a ring buffer.
	 *
	 * \note Runs in a seperate high priority thread.
	 * \param in Input sample to process.
	 * \retval sample_t Processed sample.
	 */
	sample_t process(sample_t in);

	/**
	 * \brief JACK shutdown callback.
	 *
	 * Called when the JACK server exits, sets #running to zero.
	 */
	void shutdown();

	/**
	 * \brief Update parameters.
	 *
	 * Reads the four inputs from the analogue-to-digital converter (#param),
	 * checks if any of the inputs have changed significantly.
	 *
	 * If this is the case sets #param_updated to \c true and saves the new
	 * value in #param_val.
	 */
	void param_update();

	/**
	 * \brief Main application loop.
	 *
	 * Main application loop, runs until #running is zero.
	 *
	 * Reads and sets parameters, clears and updates #display and selects and
	 * switches effects and states using joystick input.
	 *
	 * In the #EFFECT_CHAIN state the parameters of each effect can be changed
	 * and each effect can be switched out for other effects.
	 *
	 * In the #LEVEL_ADJ state the input and output levels can be adjusted
	 * (#in_level #out_level) and the current volume level for each stage in
	 * the effect chain is shown.
	 *
	 * In the #TUNER state the note (in equal temperment) closest to the current
	 * frequency with the highest intensity is shown including a bar showing how
	 * close the measured frequency is to the ideal frequency for that note.
	 *
	 * When #running is set to zero #deactivate() is called, ceasing audio
	 * processing.
	 */
	void start();

private:
	/**
	 * \brief Signal handler.
	 *
	 * Called when process recieves a \c SIGTERM or \c SIGINT signal, sets
	 * #running to zero.
	 */
	static void sigterm_handler(int sig);
	///Running flag, program exits when set to zero.
	static volatile sig_atomic_t running;

	///LCD display output.
	gui display;
	///Analogue-to-digital converter parameter inputs.
	adc param;
	///Debounced joystick up input.
	debounce joy_up;
	///Debounced joystick down input.
	debounce joy_down;
	///Debounced joystick left input.
	debounce joy_left;
	///Debounced joystick right input.
	debounce joy_right;
	///Debounced joystick push button input.
	debounce joy_push;

	///Effect manager, maintains loaded plugins.
	effect_manager effects;

	///Effect chain, list of effects to apply to audio stream.
	std::vector<effect_list> effect_chain;

	///Index of currently selected effect position (0->#NUM_EFFECTS).
	unsigned int effect_idx;

	///Ring buffer of gui::BUFFER_LENGTH samples for each part of the effect chain (see gui::level_view()).
	jack_client::sample_t sample_array[7][gui::BUFFER_LENGTH];
	///Current array index in sample_array.
	size_t sample_array_idx;

	///Ring buffer of gui::TUNER_BUFFER_LENGTH samples for the input (see gui::tuner_view()).
	jack_client::sample_t tuner_array[gui::TUNER_BUFFER_LENGTH];
	///Current array index in tuner_array.
	size_t tuner_array_idx;
	///Gausian window for tuner array
	std::vector<float> gauss;
	///Vector for holding real part of FFT result.
	std::vector<float> fft_re;
	///Vector for holding imaginary part of FFT result.
	std::vector<float> fft_im;
	///AudioFFT object for determining the frequency response of the current tuner_array.
	audiofft::AudioFFT fft;

	///Current value of each parameter.
	float param_val[NUM_PARAMS];
	///Parameter updated flag, true if given parameter has been updated.
	bool param_updated[NUM_PARAMS];

	///Input gain level (0.0->1.0).
	float in_level;
	///Output gain level (0.0->1.0).
	float out_level;

	///GUI states.
	enum disp_state
	{
		EFFECT_CHAIN, ///<Display effect chain allowing parameter configuration for each effect.
		LEVEL_ADJ,    ///<Display volume and gain levels at each part of the effect chain.
		TUNER         ///<Display the pitch of the current note, and how sharp or flat it is.
	};
	///Current GUI state.
	disp_state state;
};

#endif /*SIGNL_H*/
