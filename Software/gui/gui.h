#ifndef GUI_H
#define GUI_H
#include "sprites.h"
#include "font.h"
#include "../effects/effect.h"
#include "../hw/lcd.h"
#include <string>
#include <memory>

class gui : public lcd
{
	using lcd::lcd;
public:

private:
	void putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv = false);
	void putchar(char ch, unsigned int x_origin, unsigned int y_origin);
	void putstring(std::string str, unsigned int x_origin, unsigned int y_origin);
	void putrect(unsigned int x_origin, unsigned int y_origin, unsigned int width, unsigned int height);
	void signl_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain);
};

#endif /*GUI_H*/
