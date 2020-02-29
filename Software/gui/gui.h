#ifndef GUI_H
#define GUI_H
#include "sprites.h"
#include "font.h"
#include "../hw/lcd.h"

class gui
{
public:

	gui(lcd lcd_in);
	void putsprite(Sprite sprite, unsigned int x_origin, unsigned int y_origin, bool inv = 
false);  
	void putrect(unsigned int x_origin, unsigned int y_origin, unsigned int width, unsigned 
int height, bool fill = true);
	void putstring(char* string, unsigned int x_origin, unsigned int 
y_origin);

private:
	lcd* lcdPtr;
	void putchar(char ch, unsigned int x_origin, unsigned int 
y_origin);

};


#endif /*GUI_H*/
