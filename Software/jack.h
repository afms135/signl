#ifndef JACK_H
#define JACK_H
#include <jack/jack.h>
#include <string>

class jack_client
{
public:
	typedef jack_default_audio_sample_t sample_t;

	jack_client(std::string name);
	~jack_client();
	void activate();
	jack_nframes_t rate();
	virtual sample_t process(sample_t in) = 0;
	virtual void shutdown() = 0;

private:
	void callback(jack_nframes_t frames);
	static int callback_forwarder(jack_nframes_t frames, void *arg);
	static void shutdown_forwarder(void *arg);

	jack_client_t *client;
	jack_port_t *input_port;
	jack_port_t *output_port;
};

#endif /*JACK_H*/
