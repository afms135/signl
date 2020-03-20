#include "gui.h"

void gui::putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv)
{
	unsigned int rows = sprite.art.size()/sprite.width;
	for(unsigned int y_index = 0; y_index < rows ; y_index++)
	{
		for(unsigned int x_index = 0; x_index < sprite.width; x_index++)
		{
			putpixel(x_origin+x_index, y_origin+y_index, sprite.art[x_index+(y_index*sprite.width)]);
		}
	}
}

void gui::putchar(char ch, unsigned int x_origin, unsigned int y_origin)
{
	unsigned int font_index = 0;
	if(ch >= 'A' && ch <= 'Z')
		font_index = ch - 'A';
	else if(ch >= 'a' && ch <= 'z') // (mapped to A-Z)
		font_index = ch - 'a';
	else if(ch >= '0' && ch <= '9')
		font_index = 26 + (ch - '0');
	else
	{
		switch(ch)
		{
			case '.':  font_index = 36; break;
			case ',':  font_index = 37; break;
			case ';':  font_index = 38; break;
			case ':':  font_index = 39; break;
			case '\'': font_index = 40; break;
			case '!':  font_index = 41; break;
			case '"':  font_index = 42; break;
			case '?':  font_index = 43; break;
			default: return;
		}
	}
	putsprite(font[font_index], x_origin, y_origin);
}

void gui::putstring(std::string str, unsigned int x_origin, unsigned int y_origin)
{
	// NOTE: pixels going off screen are handled by afms135's
	//       lcd class, but I think a string long enough would
	//       eventually wrap around when this local 'x' overflows
	unsigned int x_index = x_origin;
	unsigned int y_index = y_origin;

	for(auto ch : str)
	{
		if (ch == ' ')
			x_index = x_index + 7;
		else if (ch == '\n')
		{
			x_index = x_origin;
			y_index = y_index + 7;
		}
		else
			putchar(ch, x_index, y_index);
		x_index = x_index + 7;
	}
}

// Puts a rectangle on top of the current fbuf (uses invpixel)
void gui::putrect(unsigned int x_origin, unsigned int y_origin, unsigned int width, unsigned int height)
{
	for(unsigned y_index = y_origin; y_index < y_origin + height; ++y_index)
	{
		for(unsigned x_index = x_origin; x_index < x_origin + width; ++x_index)
		{
			invpixel(x_index,y_index);
		}
	}
}

void gui::signl_view(std::vector<std::unique_ptr<effect,plugin_dtor_t>> &effect_chain, unsigned int effect_idx)
{
	unsigned int cursor_x = 0;
	unsigned int cursor_y = 0;

	// Draw main signal line
	cursor_y = 12;
	putrect(cursor_x,cursor_y,128,1);

	// Draw effect chain
	cursor_x = 5;
	cursor_y = 0;
	for(auto &e : effect_chain)
	{
		putsprite(icons[e->icon()],cursor_x,cursor_y);
		cursor_x = cursor_x + icons[e->icon()].width + 4;
	}

	// Draw arrow
	cursor_x = 5 + 6 + (effect_idx * 24);
	cursor_y = 18;
	putsprite(arrow,cursor_x,cursor_y);

	// Print name of current effect
	cursor_x = 64 - (effect_chain[effect_idx]->name().length() * 7 / 2);
	cursor_y = 28;
	putstring(effect_chain[effect_idx]->name(),cursor_x,cursor_y);
	putrect(0,26,128,10);

	// Print parameters of current effect
	cursor_x = 0;
	cursor_y = 44;
	putstring(effect_chain[effect_idx]->paramname(effect::PARAM_A).substr(0,8),cursor_x,cursor_y);

	cursor_x = 0;
	cursor_y = 52;
	putstring(effect_chain[effect_idx]->paramname(effect::PARAM_B).substr(0,8),cursor_x,cursor_y);

	cursor_x = 128 - (effect_chain[effect_idx]->paramname(effect::PARAM_C).substr(0,8).length() * 7);
	cursor_y = 44;
	putstring(effect_chain[effect_idx]->paramname(effect::PARAM_C).substr(0,8),cursor_x,cursor_y);

	cursor_x = 128 - (effect_chain[effect_idx]->paramname(effect::PARAM_D).substr(0,8).length() * 7);
	cursor_y = 52;
	putstring(effect_chain[effect_idx]->paramname(effect::PARAM_D).substr(0,8),cursor_x,cursor_y);

}
