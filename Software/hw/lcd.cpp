#include "lcd.h"
#include <chrono>
#include <thread>
#include <cstdint>

//Commands
#define ST7565_DISPOFF         (0xAE)
#define ST7565_DISPON          (0xAF)
#define ST7565_STARTLINE(line) (uint8_t)(0x40 | (line & 0x3F))
#define ST7565_PAGEADDR(addr)  (uint8_t)(0xB0 | (addr & 0x0F))
#define ST7565_COLADDRH(addr)  (uint8_t)(0x10 | (addr & 0x0F))
#define ST7565_COLADDRL(addr)  (uint8_t)(addr & 0x0F)
#define ST7565_ADCNORM         (0xA0)
#define ST7565_ADCREV          (0xA1)
#define ST7565_DISPNORMAL      (0xA6)
#define ST7565_DISPREVERSE     (0xA7)
#define ST7565_PNTNORM         (0xA4)
#define ST7565_PNTFILL         (0xA5)
#define ST7565_BIAS19          (0xA2)
#define ST7565_BIAS17          (0xA3)
#define ST7565_RESET           (0xE2)
#define ST7565_COMNORM         (0xC0)
#define ST7565_COMREV          (0xC8)
#define ST7565_PWRCTRL(mode)   (uint8_t)(0x28 | (mode & 0x7))
#define ST7565_RATIO(ratio)    (uint8_t)(0x20 | (ratio & 0x7))
#define ST7565_VOLMODE         (0x81)
#define ST7565_INDICATOROFF    (0xAC)
#define ST7565_INDICATORON     (0xAD)
#define ST7565_BOOSTRATIO      (0xF8)
#define ST7565_NOP             (0xE3)

//Init sequence
static constexpr uint8_t init_seq[] =
{
	ST7565_STARTLINE(0),       //Display start line 0
	ST7565_ADCREV,             //ADC reverse
	ST7565_COMNORM,            //Normal COM0-COM63
	ST7565_DISPNORMAL,         //Display normal
	ST7565_BIAS19,             //Set bias 1/9 (Duty 1/65)
	ST7565_PWRCTRL(7),         //Booster, Regulator and Follower on
	ST7565_BOOSTRATIO, 0x00,   //Set internal booster to 4x
	ST7565_RATIO(7),           //Contrast set
	ST7565_VOLMODE, 0x16,      //Contrast set
	ST7565_INDICATOROFF, 0x00, //No indicator
	ST7565_DISPON              //Display on
};

lcd::lcd(std::string spidev, std::string gpiochip, int A0_pin, int res_pin) :
	spi(spidev, spidev::MODE0, 8, 16000000),
	A0(gpiochip, A0_pin, 0, "LCD_A0"),
	res(gpiochip, res_pin, 1, "LCD_RES")
{
	//Reset LCD
	res = 0;
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	res = 1;
	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	//Send init sequence
	command();
	spi.send(init_seq, sizeof(init_seq));

	//Clear screen
	clear();
	flip();
}

void lcd::clear()
{
	fbuf.fill(0);
}

void lcd::flip()
{
	for(unsigned int page = 0; page < pages; page++)
	{
		command();
		uint8_t buf[] = {
			ST7565_PAGEADDR(page),
			ST7565_STARTLINE(0),
			ST7565_COLADDRH(0),
			ST7565_COLADDRL(0),
		};
		spi.send(buf, sizeof(buf));

		data();
		spi.send(&fbuf[page * width], width);
	}
}

void lcd::putpixel(unsigned int x, unsigned int y, bool val)
{
	//Clip
	if(x >= width || y >= height)
		return;

	uint8_t page = y / 8;
	uint8_t pageoff = y % 8;

	if(val)
		fbuf[(page * width) + x] |= (1 << pageoff);
	else
		fbuf[(page * width) + x] &= ~(1 << pageoff);
}

bool lcd::getpixel(unsigned int x, unsigned int y)
{
	if(x >= width || y >= height)
		return false;

	uint8_t page = y / 8;
	uint8_t pageoff = y % 8;

	return fbuf[(page * width) + x] & (1 << pageoff);
}

void lcd::invpixel(unsigned int x, unsigned int y)
{
	putpixel(x, y, !getpixel(x,y));
}

void lcd::command()
{
	A0 = 0;
}

void lcd::data()
{
	A0 = 1;
}
