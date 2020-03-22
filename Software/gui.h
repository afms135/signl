#ifndef GUI_H
#define GUI_H
#include "assets/sprites.h"
#include "assets/font.h"
#include "effects/effect.h"
#include "hw/lcd.h"
#include <string>
#include <memory>
#include "jack.h"

constexpr auto BUFFER_LENGTH = 2048;

class gui : public lcd
{
	using lcd::lcd;
public:
	void signl_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain);
	void param_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain, unsigned int effect_idx);
	void level_view(float in_level, float out_level, jack_client::sample_t sample_array[7][BUFFER_LENGTH]);

private:
	void putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv = false);
	void putchar(char ch, unsigned int x_origin, unsigned int y_origin);
	void putstring(std::string str, unsigned int x_origin, unsigned int y_origin);
	void putrect(unsigned int x_origin, unsigned int y_origin, unsigned int width, unsigned int height);
};

#endif /*GUI_H*/
