#ifndef JACK_H
#define JACK_H
#include <jack/jack.h>
#include <string>

/**
 * \brief Abstract class representing a mono JACK client
 *
 * This class is a base class that is designed to be used to represent a mono
 * JACK client that does effect processing.
 *
 * An audio processing program should inherit this class and provide a
 * #process() and #shutdown() function.
 *
 * Example:
 * \code
 * #include "jack.h"
 *
 * class client : jack_client
 * {
 * public:
 * 	client() : jack_client("Example client"), running(true)
 * 	{
 * 	}
 *
 * 	sample_t process(sample_t in)
 * 	{
 * 		return in;
 * 	}
 *
 * 	void shutdown()
 * 	{
 * 		running = 0;
 * 	}
 *
 * 	void start()
 * 	{
 * 		while(running);
 * 	}
 *
 * 	bool running;
 * };
 *
 * int main(void)
 * {
 * 	client c;
 * 	c.start();
 * 	return 0;
 * }
 * \endcode
 */
class jack_client
{
public:
	///Type used in #process() to represent audio data (usually float).
	typedef jack_default_audio_sample_t sample_t;

	/**
	 * \brief Create an instance of a JACK client.
	 *
	 * Tries to connect to a running JACK server and registers the callback
	 * functions.
	 *
	 * \note Audio processing does not begin until #activate() is called.
	 *
	 * \exception std::runtime_error If connecting to the JACK server failed.
	 * \param name String containing the name of the client.
	 */
	jack_client(std::string name);

	/**
	 * \brief Destructor.
	 *
	 * Disconnects from the JACK server, removing this client from the signal
	 * chain.
	 */
	~jack_client();

	/**
	 * \brief Activate JACK client.
	 *
	 * This activates the JACK client, connecting the client input port to
	 * the default capture device and the output port to the default playback
	 * device.
	 *
	 * Audio proccessing begins after this function is called.
	 *
	 * \exception std::runtime_error If activating the JACK client failed.
	 */
	void activate();

	/**
	 * \brief Deactivate JACK client.
	 *
	 * This deactivates the JACK client, disconnecting the input port from the
	 * default capture device and the output port from the default playback
	 * device.
	 *
	 * Audio proccessing is stopped after this function is called.
	 *
	 * \exception std::runtime_error If deactivating the JACK client failed.
	 */
	void deactivate();

	/**
	 * \brief Return JACK server sample rate.
	 *
	 * Returns the current sample rate of the JACK server.
	 *
	 * \retval jack_nframes_t Sample rate measured in Hz.
	 */
	jack_nframes_t rate();

	/**
	 * \brief JACK processing callback.
	 *
	 * Called when the JACK server has samples to process.
	 *
	 * \warning This function is called from a realtime priority thread,
	 * avoid blocking/long running function calls.
	 *
	 * \param in Sample to be processed.
	 * \retval sample_t Processed sample.
	 */
	virtual sample_t process(sample_t in) = 0;

	/**
	 * \brief JACK shutdown callback.
	 *
	 * Called when the JACK server terminates.
	 *
	 * The inherited class should terminate gracefully when this is called.
	 */
	virtual void shutdown() = 0;

private:
	/**
	 * \brief JACK callback function.
	 *
	 * This internal function retrieves the input data from the port
	 * #input_port, processes the data sample-by-sample using the #process()
	 * function and writes the processed data to the buffer provided by the port
	 * #output_port.
	 *
	 * \param frames Number of samples to process.
	 */
	void callback(jack_nframes_t frames);

	/**
	 * \brief JACK process callback forwarder.
	 *
	 * This function is used to forward the JACK process callback to this class
	 * as the JACK C API requires a \c static function as a callback.
	 * Calls #callback().
	 *
	 * \param frames Number of samples to process.
	 * \param arg Pointer to class that this callback is registered with.
	 */
	static int callback_forwarder(jack_nframes_t frames, void *arg);

	/**
	 * \brief JACK shutdown callback forwarder.
	 *
	 * This function is used to forward the JACK shutdown callback to this class
	 * as the JACK C API requires a \c static function as a callback.
	 * Calls #shutdown().
	 *
	 * \param arg Pointer to class that this callback is registered with.
	 */
	static void shutdown_forwarder(void *arg);

	jack_client_t *client; ///<Handle used to communicate with JACK server.
	jack_port_t *input_port; ///<Handle to JACK port used to read samples.
	jack_port_t *output_port; ///<Handle to JACK port used to output samples.
};

#endif /*JACK_H*/
