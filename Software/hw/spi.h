#ifndef SPI_H
#define SPI_H
#include <string>
#include <cstdint>
#include <linux/types.h>
#include <linux/spi/spidev.h>

/**
 * \brief Class representing a SPI device
 *
 * This class encapsulates a simple interface for a SPI device using the
 * Linux spidev interface defined in \c /usr/include/linux/spi/spidev.h.
 *
 * This class assumes the chip select line is associated with the kernel
 * interface. If this is not the case use the mode #NO_CS and use a standard
 * gpio line around this classes interface.
 *
 * \warning The \c spidev kernel module needs to be loaded for this class to work.
 *
 * Example:
 * \code
 * #include "spi.h"
 * #include <stdio.h>
 * #include <stdint.h>
 *
 * int main(void)
 * {
 * 	//Test SPI loop, connect MOSI to MISO
 * 	spidev dev("/dev/spidev0.0", spidev::MODE0, 8, 1000000);
 *
 * 	uint8_t buf[4] = {0xDE, 0xAD, 0xBE, 0xEF};
 * 	printf("Send: %X %X %X %X\n", buf[0], buf[1], buf[2], buf[3]);
 * 	dev.xfer(buf, 4);
 * 	printf("Recv: %X %X %X %X\n", buf[0], buf[1], buf[2], buf[3]);
 * }
 * \endcode
 */
class spidev
{
public:
	///Flags to modify SPI device transfer behaviour.
	enum modes
	{
		///Send data on rising edge of clock, recieve on falling edge.
		CPHA       = SPI_CPHA,
		///Clock line idles high.
		CPOL       = SPI_CPOL,
		///For convenience, equivalent to: \c 0.
		MODE0      = 0,
		///For convenience, equivalent to: \c CPHA.
		MODE1      = CPHA,
		///For convenience, equivalent to: \c CPOL.
		MODE2      = CPOL,
		///For convenience, equivalent to: \c CPHA \c | \c CPOL.
		MODE3      = CPHA | CPOL,
		///Chip select line is active-high.
		CS_HIGH    = SPI_CS_HIGH,
		///Send least significant bit of words first.
		LSB_FIRST  = SPI_LSB_FIRST,
		///MOSI and MISO lines are shared.
		THREE_WIRE = SPI_3WIRE,
		///Loopback mode.
		LOOP       = SPI_LOOP,
		///Do not use chip select line.
		NO_CS      = SPI_NO_CS,
		///Slave pulls low to pause transfer.
		READY      = SPI_READY,
		///Dual SPI, two MOSI lines.
		TX_DUAL    = SPI_TX_DUAL,
		///Quad SPI, four MOSI lines.
		TX_QUAD    = SPI_TX_QUAD,
		///Dual SPI, four MISO lines.
		RX_DUAL    = SPI_RX_DUAL,
		///Quad SPI, four MISO lines.
		RX_QUAD    = SPI_RX_QUAD,
	};

	/**
	 * \brief Create an instance of a SPI device.
	 *
	 * See also: #setmode, #setbpw and #setmaxspeed.
	 *
	 * \exception std::runtime_error If opening/configuring the SPI device fails.
	 * \param spidev String containing a path to a spidev device file (/dev/spidevA.B).
	 * \param m A number of flags of type #modes ored together (optional: defaults to #MODE0).
	 * \param bpw Number of bits per word (optional: defaults to 8).
	 * \param speed Maximum clock speed in Hz (optional: defaults to 8MHz).
	 */
	spidev(std::string spidev, modes m = MODE0, uint8_t bpw = 8, uint32_t speed = 8000000);

	/**
	 * \brief Set SPI operation mode.
	 *
	 * Set flags to modify SPI transfer behaviour.
	 *
	 * \exception std::runtime_error If setting the modes failed.
	 * \param m A number of flags of type #modes ored together.
	 */
	void setmode(modes m);

	/**
	 * \brief Set number of bits per word.
	 *
	 * Sets the number of bits transfered in each word.
	 *
	 * \exception std::runtime_error If setting the bits per word failed.
	 * \param bpw Number of bits per word.
	 */
	void setbpw(uint8_t bpw);

	/**
	 * \brief Set maximum clock speed.
	 *
	 * Sets the maximum clock speed that is generated on the CLK line.
	 *
	 * \exception std::runtime_error If setting the maximum speed failed.
	 * \warning Actual clock speed might be lower.
	 * \param speed Maximum clock speed in Hz.
	 */
	void setmaxspeed(uint32_t speed);

	/**
	 * \brief Full duplex transfer.
	 *
	 * Transfers and recieves data over the SPI bus simultaneously.
	 *
	 * \note Data is right aligned within each word.
	 * \exception std::runtime_error If #fd is invalid, due to a move.
	 * \param send Buffer of words to send to device.
	 * \param recv Buffer of words to recieve from device.
	 * \param len Number of words to transfer.
	 */
	void xfer(const void *send, void *recv, uint32_t len);

	/**
	 * \brief Full duplex transfer.
	 *
	 * Equivalent to calling:
	 * \code xfer (buf, buf, len) \endcode
	 *
	 * \param buf Buffer to send and recieve words from.
	 * \param len Number of words to transfer.
	 */
	void xfer(void *buf, uint32_t len);

	/**
	 * \brief Half duplex send.
	 *
	 * Equivalent to calling:
	 * \code xfer (buf, NULL, len) \endcode
	 *
	 * \param buf Buffer of words to send to device.
	 * \param len Number to words to transfer.
	 */
	void send(const void *buf, uint32_t len);

	/**
	 * \brief Half duplex recieve.
	 *
	 * Equivalent to calling:
	 * \code xfer(NULL, buf, len) \endcode
	 *
	 * \note Sends zeros on MOSI line.
	 * \param buf Buffer to store words recieved from device.
	 * \param len Number of words to transfer.
	 */
	void recv(void *buf, uint32_t len);

	///Deleted copy constructor, class can only be moved.
	spidev(const spidev& other) = delete;
	///Deleted copy assignment operator, class can only be moved.
	spidev& operator=(const spidev& other) = delete;
	///Move constuctor, transfers ownership of other.#fd to this, sets other.#fd to -1.
	spidev(spidev&& other);
	///Move assignment operator, closes #fd, transfers ownership of other.#fd to this, sets other.#fd to -1.
	spidev& operator=(spidev&& other);
	///Destructor, closes #fd.
	~spidev();

private:
	int fd; ///<File descriptor handle.
};

inline spidev::modes operator|(spidev::modes a, spidev::modes b)
{
	return static_cast<spidev::modes>(static_cast<int>(a) | static_cast<int>(b));
}

#endif /*SPI_H*/
