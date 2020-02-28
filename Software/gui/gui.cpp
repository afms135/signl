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
y_origin+y_index), sprite.art[x_index+(y_index*sprite.width)]);
		}
	}
}
