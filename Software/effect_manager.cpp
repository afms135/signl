#include "effect_manager.h"
#include "effects/amp.h"
#include "effects/overdrive.h"
#include <stdexcept>

std::unique_ptr<effect> effect_manager::operator()(int idx)
{
	switch(idx)
	{
	case 0: return std::unique_ptr<effect>(new null());
	case 1: return std::unique_ptr<effect>(new amp());
	case 2: return std::unique_ptr<effect>(new overdrive());
	default:
		throw std::runtime_error("Effect index out of range");
	}
}

int effect_manager::size()
{
	return 3;
}
