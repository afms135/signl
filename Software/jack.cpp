#include "jack.h"
#include <stdexcept>

jack_client::jack_client(std::string name)
{
	//Try and connect to the JACK server
	jack_status_t status;

	client = jack_client_open(name.c_str(), JackNoStartServer, &status);
	if(client == nullptr)
		throw std::runtime_error("jack_client_open(): Could not connect to server code: " + std::to_string(status));

	//Create input port
	input_port = jack_port_register(client, "input", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
	if(input_port == nullptr)
		throw std::runtime_error("jack_port_register(): Could not create input port");

	//Create output port
	output_port = jack_port_register(client, "output", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
	if(output_port == nullptr)
		throw std::runtime_error("jack_port_register(): Could not create output port");

	//Connect callbacks
	if(jack_set_process_callback(client, callback_forwarder, this))
		throw std::runtime_error("jack_set_process_callback(): Could not set callback");
	jack_on_shutdown(client, shutdown_forwarder, this);
}

jack_client::~jack_client()
{
	//Disconnect from JACK server
	jack_client_close(client);
}

void jack_client::activate()
{
	//Activate client
	if(jack_activate(client))
		throw std::runtime_error("jack_activate(): Could not activate client");

	//Connect capture port to input port
	const char **ports;
	ports = jack_get_ports(client, nullptr, nullptr, JackPortIsPhysical | JackPortIsOutput);
	if(ports == nullptr)
		throw std::runtime_error("jack_get_ports(): No physical capture ports");
	if(jack_connect(client, ports[0], jack_port_name(input_port)))
		throw std::runtime_error("jack_connect(): Could not connect physical output port to input port");
	free(ports);

	//Connect output port to playback port
	ports = jack_get_ports(client, nullptr, nullptr, JackPortIsPhysical | JackPortIsInput);
	if(ports == nullptr)
		throw std::runtime_error("jack_get_ports(): No physical playback ports");
	if(jack_connect(client, jack_port_name(output_port), ports[0]))
		throw std::runtime_error("jack_connect(): Could not connect output port to physical input port");
	free(ports);
}

jack_nframes_t jack_client::rate()
{
	return jack_get_sample_rate(client);
}

void jack_client::callback(jack_nframes_t frames)
{
	sample_t *in = static_cast<sample_t*> (jack_port_get_buffer(input_port, frames));
	sample_t *out = static_cast<sample_t*> (jack_port_get_buffer(output_port, frames));

	for(jack_nframes_t i = 0; i < frames; i++)
		out[i] = process(in[i]);
}

void jack_client::shutdown_forwarder(void *arg)
{
	static_cast<jack_client*>(arg)->shutdown();
}

int jack_client::callback_forwarder(jack_nframes_t frames, void *arg)
{
	static_cast<jack_client*>(arg)->callback(frames);
	return 0;
}
