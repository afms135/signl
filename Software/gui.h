#ifndef GUI_H
#define GUI_H
#include "jack.h"
#include "hw/lcd.h"
#include "assets/assets.h"
#include "effects/effect.h"
#include <string>
#include <memory>

/**
 * \brief Class used to draw user interface.
 *
 * This class encapsulates the lcd drawing code used to display the various
 * user interfaces on the lcd.
 */
class gui : public lcd
{
	using lcd::lcd;
public:
	///Number of previous samples to save, used in #level_view().
	static const unsigned int BUFFER_LENGTH = 2048;

	/**
	 * \brief Draw effect chain view.
	 *
	 * Draw the effect chain on the upper portion of the lcd using the icons
	 * returned by effect::icon().
	 *
	 * \param effect_chain Reference to effect chain to draw on lcd.
	 */
	void signl_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain);

	/**
	 * \brief Draw parameter view.
	 *
	 * Draw effect parameters on the lower portion of the lcd showing the
	 * effect name returned by effect::name(), the effect parameter names
	 * returned by effect::paramname() and shows the current value of each
	 * parameter returned by effect::paramval().
	 *
	 * Additionally draws an arrow below the currently selected effect.
	 *
	 * \param effect_chain Reference to effect chain to draw parameters from.
	 * \param effect_idx Index of effect to draw arrow under.
	 */
	void param_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain, unsigned int effect_idx);

	/**
	 * \brief Draw level view.
	 *
	 * Draw peak volume level bars for each position in the effect chain over
	 * the last #BUFFER_LENGTH samples, also show the current input and output
	 * gain.
	 *
	 * ```
	 * sample_array[0] = input multiplied by input level
	 * sample_array[1] = level after 1st effect
	 * sample_array[2] = level after 2nd effect
	 * sample_array[3] = level after 3rd effect
	 * sample_array[4] = level after 4th effect
	 * sample_array[5] = level after 5th effect
	 * sample_array[6] = output multiplied by output level
	 * ```
	 *
	 * \param in_level Input gain level (0<=in_level<=1.0).
	 * \param out_level Output gain level (0<=out_level<=1.0).
	 * \param sample_array Array of previous samples for each position in the effect chain.
	 */
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
	 * \brief Draw filled rectangle on lcd.
	 *
	 * Draw a filled rectange on lcd, inverts pixels currently in framebuffer.
	 *
	 * \param x_origin Horizontal co-ordinate (0 <= x_origin < #lcd.width).
	 * \param y_origin Vertical co-ordinate (0 <= y_origin < #lcd.height).
	 * \param width Width of rectangle in pixels.
	 * \param height Hight of rectangle in pixels.
	 */
	void putrect(unsigned int x_origin, unsigned int y_origin, unsigned int width, unsigned int height);
};

#endif /*GUI_H*/
