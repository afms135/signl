#ifndef ASSETS_H
#define ASSETS_H
#include <vector>
#include <cstdint>

typedef struct Sprite
{
	const std::vector<bool> art;
	uint8_t width;
} Sprite;

#include "font.h"
#include "sprites.h"

#endif /*ASSETS_H*/
