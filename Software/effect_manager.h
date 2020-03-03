#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H
#include "effects/effect.h"
#include <string>
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
};

#endif /*EFFECTMANAGER_H*/
