#include "adc.h"

adc::adc(std::string spidev) :
	spi(spidev, spidev::MODE0, 8, 1000000)
{
}

float adc::operator()(channel ch)
{
	//MCP3004 ADC s6.1 p21
	//First two bytes used for config, last two bytes used for ADC value rx
	uint8_t buf[3] = {};

	buf[0] = 0x01; //Start bit
	switch(ch)
	{
	case CH0: buf[1] = 0x80; break; //Single-ended, Channel 0
	case CH1: buf[1] = 0x90; break; //Single-ended, Channel 1
	case CH2: buf[1] = 0xA0; break; //Single-ended, Channel 2
	case CH3: buf[1] = 0xB0; break; //Single-ended, Channel 3
	}

	//Transfer and recieve simultaneously
	spi.xfer(buf, sizeof(buf));

	//Extract 10 bit count
	uint16_t val = ((buf[1] & 0x03) << 8) | buf[2];

	//Convert to float between 0 and 1
	return (float)val / 0x03FF;
}
