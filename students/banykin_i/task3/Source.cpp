#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

#define size 100

using namespace std;

class menu {

	string menuFunctions[size];//основной массив с именами и результатами
	string changer = ">> ";//ползунок
	int counter = 0;
	int button = 0;
	int amount = 0;//количество пунктов в меню
	

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pozition;
	short int basePozitionX = 0;
	short int basePozitionY = 0;

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

private:
	
	bool isPressed = false;

	//инициализация 
	void initial() {
	
		for (int i = 0; i < size; i++)
			menuFunctions[i] = "<...>";
	}

	void Control() {

		button = _getch();

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

	//возвращает название функции
	string GetName(int number) {

		return menuFunctions[number];
	}

	int GetNumber() {

		return counter + 1;
	}

	//задает координаты
	void SetCoordinates(int x, int y) {

		pozition.X = x;
		pozition.Y = y;

		basePozitionX = x;
		basePozitionY = y;
	}

	//базовые координаты
	void SCCPbase() {

		pozition.X = basePozitionX;
		pozition.Y = basePozitionY;
	}

	//задает начальную позицию ползунка
	void SetChangerPozition(int value) {

		counter = value - 1;
	}

	//отключение мигающего "_" в консоли
	void DisableShowConsoleCursor() {

		CONSOLE_CURSOR_INFO     showCursor;

		GetConsoleCursorInfo(hConsole, &showCursor);
		showCursor.bVisible = false;
		SetConsoleCursorInfo(hConsole, &showCursor);
	}


	bool isChoosen(int number) {

		if (number == counter && isPressed)
			return true;
		return false;
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

		SCCPbase();

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
	m.SetChangerPozition(1);
	m.SetColor(0, 2);
	m.SetChanger(">> ");

	//объявление имен пунктов меню
	m.SetName(0, "Богомол");
	m.SetName(1, "Зебра");
	m.SetName(2, "Дракон");
	//m.SetName(3, "Слоны");
	m.SetName(4, "Гепард");
	m.SetName(5, "Единорог");
	m.SetName(6, "");

	//объявление результата пункта
	//m.SetMean(0, " Насекомое из семейства настоящих богомолов отряда богомоловых. Крупное хищное насекомое с приспособленными для хватания пищи передними конечностями. Достигает в длину 42—52 мм (самец) или 48—75 мм (самка). Наиболее крупный и самый распространённый вид богомолов в Европе.");
	//m.SetMean(1, " Подрод рода лошади, включающий виды бурчеллова зебра, зебра Греви и горная зебра. Гибридные формы между зебрами и домашними лошадьми называют зеброидами, между зебрами и ослами — зебрулами. Зебры живут маленькими группами, состоящими из самок с детёнышами и одного жеребца.");
	//m.SetMean(2, " Собирательное название, объединяющее ряд мифологических и фантастических существ. Дракон связан с христианским культом святого Георгия и получил широкое распространение в европейском религиозном искусстве.");
	//m.SetMean(3, " Семейство млекопитающих отряда хоботных. В настоящее время к этому семейству относятся наиболее крупные наземные млекопитающие. Cамые крупные наземные животные на Земле. Обитают они в Юго-Восточной Азии и Африке в тропических лесах и саваннах.");
	//m.SetMean(4, " Хищное млекопитающее семейства кошачьих, обитает в большинстве стран Африки, а также на Ближнем Востоке. Это единственный современный сохранившийся представитель рода Acinonyx. Быстрейший из всех наземных млекопитающих: за 3 секунды может развивать скорость до 110 км/ч");
	//m.SetMean(5, " Мифическое существо, символизирует целомудрие, в широком смысле духовную чистоту и искания. Представляют его в виде коня c одним рогом, выходящим изо лба.");
	//	m.SetMean(6, "");

	do {

		system("cls");
		m.Start();

		for (int i = 0; i <= m.GetNumberOfFunctions(); i++) {

			if (m.isChoosen(i))
				cout << m.GetNumber() << endl << m.GetName(i);
		}
	} while (1);

	return 0;
}