#ifndef ADC_H
#define ADC_H
#include "spi.h"
#include <string>

class adc
{
public:
	enum channel
	{
		CH0,
		CH1,
		CH2,
		CH3
	};

	adc(std::string spidev);
	float operator()(channel ch);

private:
	spidev spi;
};

#endif /*ADC_H*/
