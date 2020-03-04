#ifndef SPRITES_H
#define SPRITES_H
#include <vector>
#include <cstdint>

typedef struct Sprite
{
	const std::vector<bool> art;
	uint8_t width;
} Sprite;

Sprite empty =
{
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
	20
};

Sprite amp =
{
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
	0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,
	0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,
	0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,
	0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,
	0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,
	0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,
	1,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,1,
	0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,
	0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0
	},
	20
};

Sprite pedal =
{
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,
	0,0,0,0,1,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,
	1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,
	0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0
	},
	20
};

Sprite faders =
{
	{
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
	0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,
	0,0,1,0,1,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,
	0,0,1,0,1,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,
	0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,
	0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,1,0,0,
	0,1,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,1,1,0,
	1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,
	0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,
	0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0
	},
	20
};

Sprite arrow =
{
	{
	0,0,0,1,1,0,0,0,
	0,0,1,1,1,1,0,0,
	0,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1
	},
	8
};

#endif /* SPRITES_H */