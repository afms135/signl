#ifndef GUI_H
#define GUI_H
#include "jack.h"
#include "hw/lcd.h"
#include "assets/assets.h"
#include "effects/effect.h"
#include <string>
#include <memory>

constexpr auto BUFFER_LENGTH = 2048;

class gui : public lcd
{
	using lcd::lcd;
public:
	void signl_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain);
	void param_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain, unsigned int effect_idx);
	void level_view(float in_level, float out_level, jack_client::sample_t sample_array[7][BUFFER_LENGTH]);

private:
	/**
	 * \brief Draw Sprite on lcd.
	 *
	 * Draw a Sprite object on the lcd, overwrites pixels in lcd framebuffer.
	 *
	 * \param sprite A Sprite object to draw on the lcd.
	 * \param x_origin Horizontal co-ordinate (0 <= x_origin < #lcd.width).
	 * \param y_origin Vertical co-ordinate (0 <= y_origin < #lcd.height).
	 * \param inv True to invert Sprite; False for standard (optional: defaults to false).
	 */
	void putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv = false);

	/**
	 * \brief Draw character on lcd.
	 *
	 * Draw a ASCII character on the lcd using Sprites defined in \c assets/font.cpp.
	 *
	 * \note Supported characters are A-Z 0-9 . , ; : \ ! " ? - + =
	 *
	 * \param ch ASCII character to draw.
	 * \param x_origin Horizontal co-ordinate (0 <= x_origin < #lcd.width).
	 * \param y_origin Vertical co-ordinate (0 <= y_origin < #lcd.height).
	 */
	void putchar(char ch, unsigned int x_origin, unsigned int y_origin);

	/**
	 * \brief Draw string on lcd.
	 *
	 * Draw a ASCII encoded string on the lcd using the font defined in \c assets/font.cpp.
	 *
	 * \param str String to draw.
	 * \param x_origin Horizontal co-ordinate (0 <= x_origin < #lcd.width).
	 * \param y_origin Vertical co-ordinate (0 <= y_origin < #lcd.height).
	 */
	void putstring(std::string str, unsigned int x_origin, unsigned int y_origin);

	/**
	 * \brief Draw rectangle outline on lcd.
	 *
	 * Draw a rectange outline on lcd, inverts pixels currently in framebuffer.
	 *
	 * \param x_origin Horizontal co-ordinate (0 <= x_origin < #lcd.width).
	 * \param y_origin Vertical co-ordinate (0 <= y_origin < #lcd.height).
	 * \param width Width of rectangle in pixels.
	 * \param height Hight of rectangle in pixels.
	 */
	void putrect(unsigned int x_origin, unsigned int y_origin, unsigned int width, unsigned int height);
};

#endif /*GUI_H*/
