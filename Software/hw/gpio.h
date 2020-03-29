#ifndef GPIO_H
#define GPIO_H
#include <string>

/**
 * \brief Class representing a GPIO output
 *
 * This class encapsulates a simple interface for a GPIO output using the Linux
 * gpiochip kernel interface defined in \c /usr/include/linux/gpio.h.
 *
 * Example:
 * \code
 * #include "gpio.h"
 * #include <unistd.h> //sleep()
 *
 * int main(void)
 * {
 * 	//Toggle output every second
 * 	gpioout out("/dev/gpiochip0", 42, 0, "Test Output");
 * 	while(1)
 * 	{
 * 		out = 1;
 * 		sleep(1);
 * 		out = 0;
 * 		sleep(1);
 * 	}
 * }
 * \endcode
 */
class gpioout
{
public:
	/**
	 * \brief Create an instance of a GPIO output.
	 *
	 * \param gpiochip String containg a path to a gpiochip device (/dev/gpiochipN).
	 * \param pin Pin number within the gpiochip device.
	 * \param value Default value of gpio pin (optional: defaults to low).
	 * \param label String detailing the usage of the pin (optional).
	 */
	gpioout(std::string gpiochip, int pin, bool value = 0, std::string label = "");

	/**
	 * \brief Assign value to GPIO output.
	 * \param v Value to set output; true to set pin high; false to set pin low.
	 */
	void operator=(bool v);

	gpioout(const gpioout& other) = delete;
	gpioout& operator=(const gpioout& other) = delete;
	gpioout(gpioout&& other);
	gpioout& operator=(gpioout&& other);
	~gpioout();

private:
	int fd;
};

/**
 * \brief Class representing a GPIO input
 *
 * This class encapsulates a simple interface for a GPIO input using the Linux
 * gpiochip kernel interface defined in \c /usr/include/linux/gpio.h.
 *
 * Example:
 * \code
 * #include "gpio.h"
 * #include <unistd.h> //sleep()
 * #include <iostream> //std::cout
 *
 * int main(void)
 * {
 * 	//Read input every second
 * 	gpioin in("/dev/gpiochip0", 42);
 * 	while(1)
 * 	{
 * 		if(in)
 * 			std::cout << "HIGH\n";
 * 		else
 * 			std::cout << "LOW\n";
 * 		sleep(1);
 * 	}
 * }
 * \endcode
 */
class gpioin
{
public:
	/**
	 * \brief Create an instance of an GPIO input.
	 *
	 * \param gpiochip String containg a path to a gpiochip device (/dev/gpiochipN).
	 * \param pin Pin number within the gpiochip device.
	 * \param label String detailing the usage of the pin (optional).
	 */
	gpioin(std::string gpiochip, int pin, std::string label = "");

	/**
	 * \brief Read value of GPIO input.
	 * \retval Returns true if input is high; false if input is low.
	 */
	explicit operator bool();

	gpioin(const gpioin& other) = delete;
	gpioin& operator=(const gpioin& other) = delete;
	gpioin(gpioin&& other);
	gpioin& operator=(gpioin&& other);
	~gpioin();

private:
	int fd;
};

#endif /*GPIO_H*/
