#include "signl.h"
#include <iostream>

signl::signl() :
	jack_client("signl"),
	running(1)
{
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
