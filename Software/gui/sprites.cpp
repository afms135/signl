#include "sprites.h"
#include <iostream>
sprite sprite_list[5] = {empty, amp, pedal, faders, arrow};

int main(int argc, char *argv[]){
	if (argc != 2) {
		std::cout << "Need argument to display sprite\n";
		return 1;
	}
	sprite* test = &sprite_list[atoi(argv[1])];
	for (int i = 0; i < test->art.size(); ++i) {
		if (!(i%test->width)) {
			std::cout << '\n';
		}
		std::cout << (test->art[i] ? "\u25A0" : " ") << ' ';
	}
	std::cout << '\n';
    return 0;
}
