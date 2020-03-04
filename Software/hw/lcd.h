#ifndef LCD_H
#define LCD_H
#include "spi.h"
#include "gpio.h"
#include <array>

class lcd
{
public:
	static const unsigned int width = 128;
	static const unsigned int pages = 8;
	static const unsigned int height = 64;

	lcd(std::string spidev, std::string gpiochip, int A0_pin, int res_pin);
	void clear();
	void flip();
	void putpixel(unsigned int x, unsigned int y, bool val = true);
	bool getpixel(unsigned int x, unsigned int y);
	void invpixel(unsigned int x, unsigned int y);

private:
	void command();
	void data();

	std::array<uint8_t, width * pages> fbuf;
	spidev spi;
	gpioout A0;
	gpioout res;
};

#endif /*LCD_H*/
