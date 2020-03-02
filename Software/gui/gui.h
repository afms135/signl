#ifndef GUI_H
#define GUI_H
#include "sprites.h"
#include "font.h"
#include "../hw/lcd.h"

class gui
{
public:

	gui(lcd lcd_in);

private:
	lcd* lcdPtr;
	void putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv = 
false);  
	void putchar(char ch, unsigned int x_origin, unsigned int 
y_origin);
	void putstring(char* string, unsigned int x_origin, unsigned int 
y_origin);
	void putrect(unsigned int x_origin, unsigned int y_origin, unsigned int width, unsigned 
int height, bool fill = true);
};


#endif /*GUI_H*/
