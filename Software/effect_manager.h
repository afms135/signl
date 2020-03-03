#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H
#include "effects/effect.h"
#include <memory>

class effect_manager
{
public:
	static const int EFFECT_NULL = 0;

	std::unique_ptr<effect> operator()(int idx);
	int size();

	effect_manager(const effect_manager& other) = delete;
	effect_manager& operator=(const effect_manager& other) = delete;
};

#endif /*EFFECTMANAGER_H*/
