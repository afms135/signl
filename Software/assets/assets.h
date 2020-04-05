#ifndef ASSETS_H
#define ASSETS_H
#include <vector>
#include <cstdint>

/**
 * \brief Sprite definition
 *
 * This structure defines a 1 bit-per-pixel sprite suitable for displaying
 * on a black-and-white lcd.
 *
 * Example:
 * \code
 * Sprite square =
 * {
 * 	{
 * 		1,1,1,1,1,
 * 		1,0,0,0,1,
 * 		1,0,0,0,1,
 * 		1,0,0,0,1,
 * 		1,1,1,1,1
 * 	},
 * 	5
 * };
 * \endcode
 */
struct Sprite
{
	///Vector of bits in sprite, true for set, false for clear.
	const std::vector<bool> art;
	///Width of sprite in pixels.
	uint8_t width;
};

extern Sprite icons[];
extern Sprite arrow;
extern Sprite font[];

#endif /*ASSETS_H*/
