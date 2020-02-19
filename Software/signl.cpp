#include "signl.h"
#include <iostream>
#include <stdexcept>
#include <cstring> //strerror()

volatile sig_atomic_t signl::running = 0;

signl::signl() :
	jack_client("signl")
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

	running = 1;
}

signl::~signl()
{
}

jack_client::sample_t signl::process(sample_t in)
{
    return in;
}

void signl::start()
{
	std::cout << "Starting..." << std::endl;
	while(running)
	{
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
