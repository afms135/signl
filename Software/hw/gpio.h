#ifndef GPIO_H
#define GPIO_H
#include <string>

class gpioout
{
public:
	gpioout(std::string gpiochip, int pin, bool value = 0, std::string label = "");
	void operator=(bool v);

	gpioout(const gpioout& other) = delete;
	gpioout& operator=(const gpioout& other) = delete;
	gpioout(gpioout&& other);
	gpioout& operator=(gpioout&& other);
	~gpioout();

private:
	int fd;
};

class gpioin
{
public:
	gpioin(std::string gpiochip, int pin, std::string label = "");
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
