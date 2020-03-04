#include "spi.h"
#include <stdexcept>
#include <cstring>     //strerror()
#include <sys/types.h> //open()
#include <sys/stat.h>  //open()
#include <fcntl.h>     //open()
#include <unistd.h>    //close()
#include <sys/ioctl.h> //ioctl()

spidev::spidev(std::string spidev, modes m, uint8_t bpw, uint32_t speed)
{
	//Open device
	fd = open(spidev.c_str(), O_RDWR | O_NONBLOCK);
	if(fd < 0)
		throw std::runtime_error("Could not open " + spidev + ": " + std::string(strerror(errno)));

	//Set parameters
	setmode(m);
	setbpw(bpw);
	setmaxspeed(speed);
}

void spidev::setmode(modes m)
{
	if(ioctl(fd, SPI_IOC_WR_MODE32, &m) < 0)
		throw std::runtime_error("Could not set spidev mode: " + std::to_string(m));
}

void spidev::setbpw(uint8_t bpw)
{
	if(ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bpw) < 0)
		throw std::runtime_error("Could not set spidev bits per word: " + std::to_string(bpw));
}

void spidev::setmaxspeed(uint32_t speed)
{
	if(ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0)
		throw std::runtime_error("Could not set spidev speed: " + std::to_string(speed));
}

void spidev::xfer(const void *send, void *recv, uint32_t len)
{
	struct spi_ioc_transfer msg[1] = {};

	//Setup transmit and recieve buffers
	msg[0].tx_buf = reinterpret_cast<__u64>(send);
	msg[0].rx_buf = reinterpret_cast<__u64>(recv);
	msg[0].len = len;
	//Zeros here use default values from constructor
	msg[0].speed_hz = 0;
	msg[0].bits_per_word = 0;
	msg[0].tx_nbits = 0;
	msg[0].rx_nbits = 0;
	//Deselect device after transfer
	msg[0].cs_change = 1;
	//No delays between transfers
	msg[0].delay_usecs = 0;

	//Start transfer
	if(ioctl(fd, SPI_IOC_MESSAGE(1), msg) < 0)
		throw std::runtime_error("Could not read/write to spidev: " + std::string(strerror(errno)));
}

void spidev::xfer(void *buf, uint32_t len)
{
	xfer(buf, buf, len);
}

void spidev::send(const void *buf, uint32_t len)
{
	xfer(buf, nullptr, len);
}

void spidev::recv(void *buf, uint32_t len)
{
	xfer(nullptr, buf, len);
}

spidev::spidev(spidev&& other)
{
	fd = other.fd;
	other.fd = -1;
}

spidev& spidev::operator=(spidev&& other)
{
	if(this != &other)
	{
		close(fd);
		fd = other.fd;
		other.fd = -1;
	}
	return *this;
}

spidev::~spidev()
{
	close(fd);
}
