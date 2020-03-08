#ifndef SPRITES_H
#define SPRITES_H
#include <vector>
#include <cstdint>

typedef struct Sprite
{
	const std::vector<bool> art;
	uint8_t width;
} Sprite;

Sprite icons[] =
{
	{	// empty
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
	},

	{	// amp
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
	},

	{	// pedal
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
	},

	{	// faders
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
	},

	{	// VU meter
		{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
		0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,
		0,0,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,0,0,
		0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,
		0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,
		0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,
		0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,
		0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,
		0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,
		1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,
		0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,
		0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0
		},
		20
	},

	{	// cassette tape
		{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
		0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		0,0,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,0,0,
		0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,
		0,0,1,0,1,1,0,0,1,0,0,1,1,0,0,1,0,1,0,0,
		0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,1,0,1,0,0,
		0,0,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,0,0,
		0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,0,
		0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,
		1,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,1,
		0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,
		0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0
		},
		20
	}

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
