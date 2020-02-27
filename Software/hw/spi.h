#ifndef SPI_H
#define SPI_H
#include <string>
#include <cstdint>
#include <linux/types.h>
#include <linux/spi/spidev.h>

class spidev
{
public:
	enum modes
	{
		CPHA       = SPI_CPHA,
		CPOL       = SPI_CPOL,
		MODE0      = 0,             //Clock idle low, MOSI falling, MISO rising
		MODE1      = CPHA,          //Clock idle low, MOSI rising, MISO falling
		MODE2      = CPOL,          //Clock idle high, MOSI falling, MISO rising
		MODE3      = CPHA | CPOL,   //Clock idle high, MOSI rising, MISO falling
		CS_HIGH    = SPI_CS_HIGH,   //Chip select is active-high
		LSB_FIRST  = SPI_LSB_FIRST, //Send least significant bit first
		THREE_WIRE = SPI_3WIRE,     //MISO and MOSI shared
		LOOP       = SPI_LOOP,      //Loopback mode
		NO_CS      = SPI_NO_CS,     //No chip select
		READY      = SPI_READY,     //Slave pulls low to pause transfer
		TX_DUAL    = SPI_TX_DUAL,   //Dual MOSI
		TX_QUAD    = SPI_TX_QUAD,   //Quad MOSI
		RX_DUAL    = SPI_RX_DUAL,   //Dual MISO
		RX_QUAD    = SPI_RX_QUAD,   //Quad MISO
	};

	spidev(std::string spidev, modes m = MODE0, uint8_t bpw = 8, uint32_t speed = 8000000);
	void setmode(modes m);
	void setbpw(uint8_t bpw);
	void setmaxspeed(uint32_t speed);

	void send(const void *buf, uint32_t len);
	void recv(void *buf, uint32_t len);
	void xfer(const void *send, void *recv, uint32_t len);
	void xfer(void *buf, uint32_t len);

	spidev(const spidev& other) = delete;
	spidev& operator=(const spidev& other) = delete;
	spidev(spidev&& other);
	spidev& operator=(spidev&& other);
	~spidev();

private:
	int fd;
};

inline spidev::modes operator|(spidev::modes a, spidev::modes b)
{
	return static_cast<spidev::modes>(static_cast<int>(a) | static_cast<int>(b));
}

#endif /*SPI_H*/
