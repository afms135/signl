#ifndef LCD_H
#define LCD_H
#include "spi.h"
#include "gpio.h"
#include <array>

/**
 * \brief Class representing a DOGM128 128x64 LCD display
 *
 * This class encapsulates a simple interface for the DOGM128 LCD display
 * (https://www.lcd-module.com/eng/pdf/grafik/dogm128e.pdf).
 *
 * This class maintains an internal framebuffer that can be queried and
 * manipulated using the #clear(), #putpixel(), #getpixel() and #invpixel()
 * functions. This internal framebuffer is displayed on the LCD using the
 * #flip() function.
 *
 * Example:
 * \code
 * #include "lcd.h"
 * #include <stdlib.h> //rand()
 *
 * int main(void)
 * {
 * 	//Set random pixels on LCD
 * 	lcd display("/dev/spidev0.0", "/dev/gpiochip0", 42, 43);
 * 	while(1)
 * 	{
 * 		display.invpixel(rand()%display::width, rand()%display::height);
 * 		display.flip();
 * 	}
 * }
 * \endcode
 */
class lcd
{
public:
	static const unsigned int pages = 8; ///<Number of 8 pixel high LCD pages.
	static const unsigned int width = 128; ///<Width of LCD in pixels.
	static const unsigned int height = pages * 8; ///<Height of LCD in pixels.

	/**
	 * \brief Create an instance of an LCD display.
	 *
	 * \param spidev String containing a path to a spidev device file (/dev/spidevA.B).
	 * \param gpiochip String containg a path to a gpiochip device file (/dev/gpiochipN).
	 * \param A0_pin Pin number within the gpiochip device connected to the A0 pin.
	 * \param res_pin Pin number within the gpiochip device connected to the reset pin.
	 */
	lcd(std::string spidev, std::string gpiochip, int A0_pin, int res_pin);

	/**
	 * \brief Clear framebuffer.
	 *
	 * Clears all pixels in internal framebuffer.
	 *
	 * \warning Does not take effect until #flip() is called.
	 */
	void clear();

	/**
	 * \brief Transfer framebuffer to LCD.
	 *
	 * Writes the internal framebuffer to the LCD usig the SPI bus #spi.
	 */
	void flip();

	/**
	 * \brief Set pixel in framebuffer.
	 *
	 * \note Does nothing if x or y are out of bounds.
	 * \warning Does not take effect until #flip() is called.
	 *
	 * \param x Horizontal co-ordinate (0 <= x < #width).
	 * \param y Vertical co-ordinate (0 <= y < #height).
	 * \param val True to set pixel; false to clear pixel (optional: defaults to true).
	 */
	void putpixel(unsigned int x, unsigned int y, bool val = true);

	/**
	 * \brief Read pixel from framebuffer.
	 *
	 * \note Returns false if x or y are out of bounds.
	 * \warning Does not take effect until #flip() is called.
	 *
	 * \param x Horizontal co-ordinate (0 <= x < #width).
	 * \param y Vertical co-ordinate (0 <= y < #height).
	 * \retval bool true if pixel set; false if pixel clear.
	 */
	bool getpixel(unsigned int x, unsigned int y);

	/**
	 * \brief Invert pixel in framebuffer.
	 *
	 * \note Does nothing if x or y are out of bounds.
	 * \warning Does not take effect until #flip() is called.
	 *
	 * \param x Horizontal co-ordinate (0 <= x < #width).
	 * \param y Vertical co-ordinate (0 <= y < #height).
	 */
	void invpixel(unsigned int x, unsigned int y);

private:
	///Puts LCD into command mode, by setting A0 low.
	void command();
	///Puts LCD into data mode, by setting A0 high.
	void data();

	std::array<uint8_t, width * pages> fbuf; ///<Internal bitpacked framebuffer, uses same representation as LCD.
	spidev spi; ///<SPI bus.
	gpioout A0; ///<Command/Data pin.
	gpioout res; ///<Reset pin.
};

#endif /*LCD_H*/
