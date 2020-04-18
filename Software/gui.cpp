#include "gui.h"
#include <algorithm>
#include <cmath>
#include <iterator>

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
			case '-':  font_index = 44; break;
			case '+':  font_index = 45; break;
			case '=':  font_index = 46; break;
			case '#':  font_index = 47; break;
			case '\\': font_index = 48; break;
			case '/':  font_index = 49; break;
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

void gui::signl_view(std::vector<effect_list> &effect_chain)
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
		putsprite(icons[e()->icon()],cursor_x,cursor_y);
		cursor_x = cursor_x + icons[e()->icon()].width + 4;
	}
}

void gui::param_view(std::vector<effect_list> &effect_chain, unsigned int effect_idx)
{
	unsigned int cursor_x = 0;
	unsigned int cursor_y = 0;

	// Draw arrow
	cursor_x = 5 + 6 + (effect_idx * 24);
	cursor_y = 18;
	putsprite(arrow,cursor_x,cursor_y);

	// Print name of current effect
	cursor_x = 64 - (effect_chain[effect_idx]()->name().length() * 7 / 2);
	cursor_y = 28;
	putstring(effect_chain[effect_idx]()->name(),cursor_x,cursor_y);
	putrect(0,26,128,10);

	// Print parameters of current effect
	cursor_x = 2;
	cursor_y = 44;
	putstring(effect_chain[effect_idx]()->paramname(effect::PARAM_A).substr(0,8),cursor_x,cursor_y);

	cursor_x = 2;
	cursor_y = 56;
	putstring(effect_chain[effect_idx]()->paramname(effect::PARAM_B).substr(0,8),cursor_x,cursor_y);

	cursor_x = 126 - (effect_chain[effect_idx]()->paramname(effect::PARAM_C).substr(0,8).length() * 7);
	cursor_y = 44;
	putstring(effect_chain[effect_idx]()->paramname(effect::PARAM_C).substr(0,8),cursor_x,cursor_y);

	cursor_x = 126 - (effect_chain[effect_idx]()->paramname(effect::PARAM_D).substr(0,8).length() * 7);
	cursor_y = 56;
	putstring(effect_chain[effect_idx]()->paramname(effect::PARAM_D).substr(0,8),cursor_x,cursor_y);

	// Print parameter bars
	cursor_x = 0;
	cursor_y = 42;
	putrect(cursor_x,cursor_y,effect_chain[effect_idx]()->paramval(effect::PARAM_A)*60,10);

	cursor_y = 54;
	putrect(cursor_x,cursor_y,effect_chain[effect_idx]()->paramval(effect::PARAM_B)*60,10);

	cursor_x = 126;
	cursor_y = 42;
	unsigned int current_val = effect_chain[effect_idx]()->paramval(effect::PARAM_C)*60;
	putrect(128 - current_val,cursor_y,current_val,10);

	current_val = effect_chain[effect_idx]()->paramval(effect::PARAM_D)*60;
	cursor_y = 54;
	putrect(128 - current_val,cursor_y,current_val,10);
}

void gui::level_view(float in_level, float out_level, jack_client::sample_t sample_array[7][BUFFER_LENGTH])
{
	// Show bar outlines
	for(int x = 0; x < 128; x = x + 23)
	{
		putrect(x,28,10,36);
		putrect(x+1,29,8,34);

		int k = 0;
		for(int j = 28; j + k < 64; j = j + k)
		{
			putrect(x+11,j + k++,2,1);
		}
	}

	// Calculate maximum of current buffer in dB
	float max_dB[7] = {0};
	for(int i = 0; i < 7; ++i)
	{
		max_dB[i] = 20*log10(*std::max_element(sample_array[i],sample_array[i]+BUFFER_LENGTH))+60;
	}

	// Show dB bars
	int i = 0;	// def should be a loop of i < 7
	for(int x = 0; x < 128; x = x + 23)
	{
		int h = max_dB[i++]*34/60;
		if(h > 34)
		{
			h = 34;
			putrect(x+1,24,8,2);
		}
		putrect(x+1,63-h,8,h);
	}
}

void gui::tuner_view(float fft_data[TUNER_BUFFER_LENGTH])
{
	//Find the peak of the fft
	float* max_fft = std::max_element(fft_data,fft_data+TUNER_BUFFER_LENGTH);
	//Find its frequency in Hz (using Gaussian interpolation)
	unsigned int km = std::distance(fft_data,max_fft);
	float delta_m = log(fft_data[km+1]/fft_data[km-1]) / (2*log(pow(fft_data[km],2)/(fft_data[km-1]*fft_data[km+1])));
	float freq = (km + delta_m) * 48000.0f / 32768.0f;
	//Find how many semitones from A4 = 440Hz it is (equal temperment)
	float steps = log(freq/440)/log(pow(2,1.0f/12.0f));
	//Find the closest note
	std::string note = " ";
	int closest_note = (int)round(steps);
	//Find how far from the closest note we are
	float distance = steps - closest_note;
	//Get string representation of closest note
	closest_note %= 12;
	if (closest_note < 0)
		 closest_note += 12;
	switch(closest_note)
	{
		case 0:  note = "A"; break;
		case 1:  note = "A#/B\\"; break;	// the '\' symbol is used for the flat 'b' in font.cpp
		case 2:  note = "B"; break;
		case 3:  note = "C"; break;
		case 4:  note = "C#/D\\"; break;
		case 5:  note = "D"; break;
		case 6:  note = "D#/E\\"; break;
		case 7:  note = "E"; break;
		case 8:  note = "F"; break;
		case 9:  note = "F#/G\\"; break;
		case 10: note = "G"; break;
		case 11: note = "G#/A\\"; break;
		case 12: note = "A"; break;
	}
	//Print the closest note
	putstring(note,61-(7*(note.length()-1)/2),26);
	//Print a bar for how far from note (left for flat, right for sharp)
	putrect(0,40,128,20);
	putrect(56,41,16,18);
	putrect((int)round((distance*126.0f)+61),43,6,15);
}
