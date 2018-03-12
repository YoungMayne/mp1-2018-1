#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

#define size 100

using namespace std;

class menu {
	string menuFunctions[size];//основной массив с именами
	string changer = ">> ";//ползунок
	int counter = 0;//переменная , двигающая ползунок
	int amount = 0;//количество пунктов в меню
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pozition;
	short int basePozitionY = 0;
	bool isPressed = false;
	enum Color {
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};//выбор цвета

	//инициализация 
	void initial() {
		for (int i = 0; i < size; i++)
			menuFunctions[i] = "";
	}
	//функция управления
	void Control() {
		int button = _getch(); //номер нажатой клавиши

		if (button == 80)
			counter++;
		if (button == 72)
			counter--;
		if (button == 13)
			isPressed = true;

		counter = (counter + amount + 1) % (amount + 1);
	}

public:
	menu() {
		initial();
	}
	//задает вид ползунка
	void SetChanger(string type) {
		changer = type;
	}
	//устанавливает число функций
	void SetNumberOfFunctions(int number) {
		amount = number;
	}
	//возвращает число функций
	int GetNumberOfFunctions() {
		return amount;
	}
	//дает имя ячейке
	void SetName(int number, string name) {
		menuFunctions[number] = name;

		if (amount < number)
			amount = number;
	}
	//возвращает номер функции
	int GetNumber() {
		return counter + 1;
	}
	//задает координаты
	void SetCoordinates(int x, int y) {
		pozition.X = x;
		pozition.Y = y;

		basePozitionY = y;
	}
	//отключение мигающего "_" в консоли
	void DisableShowConsoleCursor() {
		CONSOLE_CURSOR_INFO     showCursor;

		GetConsoleCursorInfo(hConsole, &showCursor);
		showCursor.bVisible = false;
		SetConsoleCursorInfo(hConsole, &showCursor);
	}
	//возвращает значение выбранного пункта меню
	int Choosen() {
		if (isPressed)
			return counter + 1;
	}
	//настройка цвета фона и текста
	void SetColor(int bg, int txt) {
		SetConsoleTextAttribute(hConsole, (WORD)((Color(bg) << 4) | Color(txt)));
	}
	//вывод на экран с учетом координат
	void Start() {
		for (int i = 0; i <= amount; i++) {
			SetConsoleCursorPosition(hConsole, pozition);

			if (i == counter) {
				cout << changer << menuFunctions[i] << endl;
			}
			else {
				cout << i + 1 << ". " << menuFunctions[i] << endl;
			}

			pozition.Y++;
		}

		SetConsoleCursorPosition(hConsole, pozition);

		pozition.Y = basePozitionY;

		isPressed = false;

		Control();
	}

};

int main() {
	setlocale(LC_ALL, "Russian");

	menu m;

	m.DisableShowConsoleCursor();
	m.SetNumberOfFunctions(0); // функция бесполезна т.к. переменная числа функций меняется динамически при объявлении нового элемента меню
	m.SetCoordinates(0, 0);
	m.SetColor(0, 2);
	m.SetChanger(">> ");

	//объявление имен пунктов меню
	m.SetName(0, "Пункт 1");
	m.SetName(1, "Пункт 2");
	m.SetName(2, "Пункт 3");
	m.SetName(3, "Пункт 4");
	m.SetName(4, "Пункт 5");
	m.SetName(5, "Пункт 6");
	m.SetName(6, "Пункт 7");

	do {
		system("cls");
		m.Start();

		cout << m.Choosen();

	} while (1);

	return 0;

}