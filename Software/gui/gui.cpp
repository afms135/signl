#include "gui.h"


gui::gui(lcd lcd_in) 
{
	lcdPtr = &lcd_in;	
}

void gui::putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv)
{
	unsigned int rows = sprite.width/sprite.art.size();
	for(unsigned int y_index = 0; y_index < rows ; ++y_index) 
	{
		for(unsigned int x_index = 0; x_index < sprite.width; ++x_index)
		{
			lcdPtr->putpixel(x_origin+x_index, 
y_origin+y_index), sprite.art[x_index+(y_index*sprite.width)]-inv);
		}
	}
}

void gui::putchar(char ch, unsigned int x_origin, unsigned int y_origin)
{
	unsigned int font_index = 0;
	if(ch > 64 && ch < 91) 			// A-Z
		font_index = ch - 65;
	else if(ch > 96 && ch < 123) 	// a-z (mapped to A-Z)
		font_index = ch - 97;
	else if(ch > 47 && ch < 58) 	// 0-9
		font_index = ch - 22;
	else 
	{
		switch(ch)
		{
			case 33: font_index = 41; break;	// !
			case 34: font_index = 42; break;	// "
			case 39: font_index = 40; break;	// '
			case 44: font_index = 37; break;	// ,
			case 46: font_index = 36; break;	// .
			case 58: font_index = 39; break;	// :
			case 59: font_index = 38; break;	// ;
			case 64: font_index = 43; break;	// ?
			default: return 1;
		}
	}

	putsprite(font[font_index], x_origin, y_origin);

}

void gui::putstring(char* string, x_origin, y_origin)
{
	// NOTE: pixels going off screen are handled by afms135's
	//       lcd class, but I think a string long enough would
 	//		 eventually wrap around when this local 'x' overflows
	unsigned int x_index = x_origin;
	unsigned int y_index = y_origin;

	for(char* ch = string; *ch; ++ch)
	{
		if (*ch = ' ')
			x_index = x_index + 7;
		else if (*ch = '\n')
			x_index = x_origin;
			y_index = y_index + 7;
		else
			putchar(*ch, x_index, y_index);
		x_index = x_index + 7;
	}
}

// Puts a rectangle on top of the current fbuf (uses invpixel)
void gui::putrect(unsigned int x_origin, unsigned int y_origin, unsigned 
int width, unsigned int height)
{
	for(unsigned y_index = y_origin; y_index < y_origin + height; 
++y_index)
	{
		for(unsigned x_index = x_origin; x_index < x_origin + width; 
++x_index)
		{
			lcdPtr->invpixel(x_index,y_index);
		}
	}
}

void gui::signl_view(std::vector<std::unique_ptr<effect>> effect_chain)
{
	unsigned int cursor = 4;
	for(auto &e : effect_chain)
	{
		putsprite(empty,cursor,4);
		cursor = cursor + 24;
	}
}
