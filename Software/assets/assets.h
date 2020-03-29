#ifndef ASSETS_H
#define ASSETS_H
#include <vector>
#include <cstdint>

struct Sprite
{
	const std::vector<bool> art;
	uint8_t width;
};

extern Sprite icons[];
extern Sprite arrow;
extern Sprite font[];

#endif /*ASSETS_H*/
