#include "menu.h"

menu::menu() {
	DisableShowConsoleCursor();
}

void menu::SetName(std::string name) {
	menuFunctions[amount] = name;

	amount++;
}

void menu::SetCoordinates(int x, int y) {
	pozition.X = x;
	pozition.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozition);
}

void menu::DisableShowConsoleCursor() {
	CONSOLE_CURSOR_INFO     showCursor;

	GetConsoleCursorInfo(hConsole, &showCursor);
	showCursor.bVisible = false;
	SetConsoleCursorInfo(hConsole, &showCursor);
}

void menu::Control() {
	int button = _getch(); 

	if (button == 80)
		counter++;
	if (button == 72)
		counter--;
	if (button == 13)
		isPressed = true;

	counter = (counter + amount) % (amount);
}

int menu::Choosen() {
	if (isPressed)
		return counter;
}

void menu::Start() {
	SetCoordinates(0, 0);
	for (int i = 0; i < amount; i++) {

		if (i == counter) {
			if (counter > 8)
				std::cout << ">>  " << menuFunctions[i] << std::endl;
			else
				std::cout << ">> " << menuFunctions[i] << std::endl;
		}
		else
			std::cout << i + 1 << ". " << menuFunctions[i] << std::endl;
	}

	isPressed = false;

	Control();
}
