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
};

#endif /*EFFECTMANAGER_H*/
