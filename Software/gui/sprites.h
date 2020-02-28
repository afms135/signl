#include <vector>

typedef struct Sprite {
	const std::vector<bool> art;
	uint8_t width;
} Sprite;

Sprite empty =
{
.art =
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
.width = 20
};

Sprite amp =
{
.art =
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
.width = 20
};

Sprite pedal =
{
.art =
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
.width = 20
};

Sprite faders =
{
.art =
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
.width = 20
};

Sprite arrow =
{
.art =
	{
	0,0,0,1,1,0,0,0,
	0,0,1,1,1,1,0,0,
	0,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1
	},
.width = 8
};
