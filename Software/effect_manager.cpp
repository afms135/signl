#include "effect_manager.h"
#include <stdexcept>
#include <glob.h>  //glob(), globfree()

effect_manager::effect_manager(std::string path, std::string ext)
{
	//Search for plugins
	glob_t b;
	std::string search_path = path + "/*" + ext;
	if(glob(search_path.c_str(), 0, nullptr, &b) != 0)
		throw std::runtime_error("Error searching path: " + search_path);

	//Open each found plugin
	for(unsigned long i = 0; i < b.gl_pathc; i++)
	{
	}

	globfree(&b);
}

std::unique_ptr<effect> effect_manager::operator()(int idx)
{
	switch(idx)
	{
	case 0: return std::unique_ptr<effect>(new null());
	default:
		throw std::runtime_error("Effect index out of range");
	}
}

int effect_manager::size()
{
	return 1;
}
