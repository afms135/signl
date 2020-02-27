#include "gpio.h"
#include <stdexcept>
#include <cstring>     //strerror()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>     //open()
#include <sys/ioctl.h> //ioctl()
#include <unistd.h>    //close()
#include <linux/gpio.h>

gpioout::gpioout(std::string gpiochip, int pin, bool value, std::string label)
{
	//Open gpiochip device file
	int req_fd = open(gpiochip.c_str(), O_RDWR | O_NONBLOCK);
	if(req_fd < 0)
		throw std::runtime_error("Could not open " + gpiochip + ": " + std::string(strerror(errno)));

	//GPIO pin request
	struct gpiohandle_request req = {};
	req.flags = GPIOHANDLE_REQUEST_OUTPUT;
	req.lines = 1;
	req.lineoffsets[0] = pin;
	req.default_values[0] = value;
	strncpy(req.consumer_label, label.c_str(), 32 - 1);
	req.consumer_label[32 - 1] = '\0';

	//Request GPIO pin
	if(ioctl(req_fd, GPIO_GET_LINEHANDLE_IOCTL, &req) < 0)
		throw std::runtime_error("Could not request gpio pin " + std::to_string(pin) + ": " + std::string(strerror(errno)));

	//Success
	fd = req.fd;
	close(req_fd);
}

void gpioout::operator=(bool v)
{
	struct gpiohandle_data data = {0};
	data.values[0] = v;
	if(ioctl(fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data) < 0)
		throw std::runtime_error("Could not set GPIO: " + std::string(strerror(errno)));
}

gpioout::gpioout(gpioout&& other)
{
	fd = other.fd;
	other.fd = -1;
}

gpioout& gpioout::operator=(gpioout&& other)
{
	if(this != &other)
	{
		close(fd);
		fd = other.fd;
		other.fd = -1;
	}
	return *this;
}

gpioout::~gpioout()
{
	close(fd);
}
