#ifndef GUI_H
#define GUI_H
#include "sprites.h"
#include "../hw/lcd.h"

class gui
{
public:

	gui(lcd lcd_in);
	void putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv = 
false);  

private:
	lcd* lcdPtr;

};


#endif /*GUI_H*/
