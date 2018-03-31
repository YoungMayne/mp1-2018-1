#include "menu.h"
#include "Temperature.h"

menu::menu(){Init();}


menu::~menu() { Init(); }

void menu::Control() {
	int button = _getch(); //номер нажатой клавиши

	if (button == 80)
		counter++;
	if (button == 72)
		counter--;
	if (button == 13)
		isPressed = true;

	counter = (counter + amount + 1) % (amount + 1);
}

void menu::SetName(int number, string name) {
	menuFunctions[number] = name;

	if (amount < number)
		amount = number;
}


void menu::DisableShowConsoleCursor() {
	CONSOLE_CURSOR_INFO     showCursor;

	GetConsoleCursorInfo(hConsole, &showCursor);
	showCursor.bVisible = false;
	SetConsoleCursorInfo(hConsole, &showCursor);
}

int menu::Choosen() {
	if (isPressed)
		return counter + 1;
}

void menu::Start() {
	for (int i = 0; i <= amount; i++) {

		if (i == counter) {
			if(counter > 8)
				cout << ">>  " << menuFunctions[i] << endl;
			else
				cout << ">> " << menuFunctions[i] << endl;
		}
		else
			cout << i + 1 << ". " << menuFunctions[i] << endl;
	}

	isPressed = false;

	Control();
}

ostream& operator<<(ostream& os, const string& dt)
{
	os << dt;

	return os;
}