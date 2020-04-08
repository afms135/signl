#include "effect_manager.h"
#include <stdexcept>
#include <glob.h>  //glob(), globfree()
#include <dlfcn.h> //dlopen(), dlsym(), dlclose(), dlerror()
#include <iostream>

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
		//Open plugin
		void *handle = dlopen(b.gl_pathv[i], RTLD_NOW);
		if(handle == nullptr)
		{
			std::cerr << "dlopen(): " + std::string(b.gl_pathv[i]) + ": " + std::string(dlerror()) << std::endl;
			continue;
		}

		//Find create/destroy functions
		void *create = dlsym(handle, "plugin_create");
		void *destroy = dlsym(handle, "plugin_destroy");
		if(create == nullptr || destroy == nullptr)
		{
			std::cerr << "dlsym(): " << std::string(b.gl_pathv[i]) + ": " + std::string(dlerror()) << std::endl;
			dlclose(handle);
			continue;
		}

		//Add to plugin list
		plugin p;
		p.handle  = handle;
		p.create  = reinterpret_cast<plugin_ctor_t>(create);
		p.destroy = reinterpret_cast<plugin_dtor_t>(destroy);
		plugins.push_back(p);
	}

	globfree(&b);
}

std::unique_ptr<effect, plugin_dtor_t> effect_manager::operator()(unsigned int idx, unsigned int rate)
{
	if(idx >= size())
		throw std::runtime_error("Effect index out of range");

	if(idx == 0)
		return std::unique_ptr<effect, plugin_dtor_t>(new null(), [](effect *e){delete e;});
	else
	{
		plugin p = plugins[idx - 1];
		return std::unique_ptr<effect, plugin_dtor_t>(p.create(rate), p.destroy);
	}
}

unsigned int effect_manager::size()
{
	return plugins.size() + 1; //+1 for NULL plugin
}

effect_manager::effect_manager(effect_manager&& other)
{
	plugins = std::move(other.plugins);
}

effect_manager& effect_manager::operator=(effect_manager&& other)
{
	if(this != &other)
	{
		for(auto p : plugins)
			dlclose(p.handle);
		plugins.clear();
		plugins = std::move(other.plugins);
	}
	return *this;
}

effect_manager::~effect_manager()
{
	for(auto p : plugins)
		dlclose(p.handle);
	plugins.clear();
}
