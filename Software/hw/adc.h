#ifndef ADC_H
#define ADC_H
#include "spi.h"
#include <string>

/**
 * \brief Class representing the MCP3004 analogue to digital converter
 *
 * This class encapsulates a simple interface for the four input MCP3004 ADC
 * (https://www.microchip.com/wwwproducts/en/MCP3004) connected over a SPI bus.
 *
 * This class returns a floating point output between 0.0 and 1.0 where 0.0
 * represents GND and 1.0 represents VCC.
 *
 * Example:
 * \code
 * #include "lcd.h"
 * #include <unistd.h> //sleep()
 * #include <cout> //std::cout
 *
 * int main(void)
 * {
 * 	//Read ADC values every second
 * 	adc in("/dev/spidev0.0");
 * 	while(1)
 * 	{
 * 		std::cout << "Values: " <<
 * 			in(adc::CH0) << ' '
 * 			in(adc::CH1) << ' '
 * 			in(adc::CH2) << ' '
 * 			in(adc::CH3) << '\n';
 * 		sleep(1);
 * 	}
 * }
 * \endcode
 */
class adc
{
public:
	///\brief MCP3004 channel inputs.
	enum channel
	{
		CH0, ///<Channel 0, pin 1.
		CH1, ///<Channel 1, pin 2.
		CH2, ///<Channel 2, pin 3.
		CH3  ///<Channel 3, pin 4.
	};

	/**
	 * \brief Create an instance of an ADC.
	 *
	 * \param spidev String containing a path to a spidev device file (/dev/spidevA.B).
	 */
	adc(std::string spidev);

	/**
	 * \brief Read from a ADC channel.
	 *
	 * \param ch Input channel to read from.
	 * \retval float Value between 0.0f and 1.0f.
	 */
	float operator()(channel ch);

private:
	spidev spi; ///<SPI bus.
};

#endif /*ADC_H*/
