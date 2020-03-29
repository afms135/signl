#ifndef DEBOUNCE_H
#define DEBOUNCE_H
#include "gpio.h"
#include <string>
#include <chrono>

/**
 * \brief Class representing a debounced GPIO input
 *
 * This class encapsulates a simple interface for a debounced GPIO input, ensuring
 * an input is active for a certain amount of time before registering a input.
 *
 * This class inherits form the gpioin class.
 *
 * Example:
 * \code
 * #include "debounce.h"
 * #include <iostream> //std::cout
 *
 * int main(void)
 * {
 * 	debounce in("/dev/gpiochip0", 42, false, 20, "Test Input");
 * 	while(1)
 * 	{
 * 		if(in)
 * 			std::cout << "PRESSED\n";
 * 	}
 * }
 * \endcode
 */
class debounce : public gpioin
{
public:
	/**
	 * \brief Create an instance of a debounced GPIO input.
	 *
	 * \param gpiochip String containg a path to a gpiochip device (/dev/gpiochipN).
	 * \param pin Pin number within the gpiochip device.
	 * \param active True if input is active high; false if input is active low (optional: defaults to active high).
	 * \param time Amount of time in milliseconds that input needs to be active (optional: defaults to 20ms).
	 * \param label String detailing the usage of the pin (optional).
	 */
	debounce(std::string gpiochip, int pin, bool active = true, int time = 20, std::string label = "");

	/**
	 * \brief Read value of debounced input.
	 * \retval Returns true if input was pressed; false otherwise.
	 */
	explicit operator bool();

private:
	bool last_val; ///<Last value of input.
	const bool active; ///<true if input is active high; false if active low.
	std::chrono::time_point<std::chrono::steady_clock> start_time; ///<Timestamp of last detected edge.
	const std::chrono::milliseconds debounce_time; ///<Time that input needs to be active to register a press.
};

#endif /*DEBOUNCE_H*/
