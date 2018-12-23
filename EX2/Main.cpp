#include <iostream>
#include "Game.h"

using std::cout;

int main() {
	cout << "Press 1 to Start BOMBERMAN!\nPress 0 to EXIT\n";
	while (getchar() == '1') {
		Game bomberman;
		bomberman.run();
	}
	return EXIT_SUCCESS;
}
