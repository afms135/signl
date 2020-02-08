#include <iostream>
#include "signl.h"

int main()
{
	try
	{
		signl s;
		s.start();
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
}
