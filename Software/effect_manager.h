#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H
#include "effects/effect.h"
#include <string>
#include <vector>
#include <memory>

class effect_manager
{
public:
	static const int EFFECT_NULL = 0;

	effect_manager(std::string path, std::string ext = ".so");
	std::unique_ptr<effect, plugin_dtor_t> operator()(int idx);
	int size();

	effect_manager(const effect_manager& other) = delete;
	effect_manager& operator=(const effect_manager& other) = delete;
	~effect_manager();

private:
	struct plugin
	{
		void *handle;
		plugin_ctor_t create;
		plugin_dtor_t destroy;
	};
	std::vector<struct plugin> plugins;
};

#endif /*EFFECTMANAGER_H*/
