#include "signl.h"
#include <iostream>
#include <cstdlib>

int main()
{
	try
	{
		signl s;
		s.start();
		return EXIT_SUCCESS;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
