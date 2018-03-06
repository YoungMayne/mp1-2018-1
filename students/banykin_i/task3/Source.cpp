#include <iostream>
#include <conio.h>
#include <Windows.h>

#define size 10

using namespace std;

class menu {
	const char* changer = " ";
	int counter = 0;
	int button = 0;
	int amount = 0;//количество пунктов в меню
	enum Direction { pressed, stay }dir = stay;
	const char* menuFunctions[size][size];//основной массив с именами и результатами
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//смена цвета
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
	}background = Black, text = White;//выбор цвета
private:
	int x = 0;//координата по иксу
	int y = 0;//по игреку
	 //инициализация ответов, что бы ничего не выводить если не задан ответ
	void initial() {
		for (int i = 0; i < size; i++)
			menuFunctions[0][i] = " ";
	}
public:
	menu() {
		initial();
	}
	//задает вид ползунка
	void SetChanger(const char* type) {
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
	void SetName(int number, const char* name) {
		menuFunctions[number][0] = name;
		amount++;
	}
	//возвращает название функции
	const char* GetNameOfFunction(int number) {
		return menuFunctions[number][0];
	}
	//дает ячейке значение при ее открытии
	void SetMean(int number, const char* string) {
		menuFunctions[0][number + 1] = string;
	}
	//выдает значение при открытии
	const char* GetMeans(int number) {
		return menuFunctions[0][number + 1];
	}
	//задает координаты
	void SetCoordinates(int X, int Y) {
		x = X;
		y = Y;
	}
	//задает начальную позицию ползунка
	void SetPozition(int value) {
		counter = value - 1;
	}
	//возвращает позицию
	int GetPozition() {
		return counter;
	}
	//движение "по кругу"
	void Move() {
		counter = (counter + amount) % (amount);
	}
	//главная функция управления
	void Control(int direction) {
		button = direction;
		if (button == 80)
			counter++;
		if (button == 72)
			counter--;
		if (button == 13)
			dir = pressed;
	}
	//выдает значение выбранного элемента меню
	void Drop() {
		if (dir == pressed) {
			for (int i = 0; i < x - 1; i++)
				cout << " ";
			cout << GetMeans(counter);
			dir = stay;
		}
	}
	//настройка цвета фона и текста
	void SetColor(int bg, int txt) {
		background = Color(bg);
		text = Color(txt);
		SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
	}
	//вывод на экран с учетом координат
	void Print() {
		for (int i = 0; i < y; i++)
			cout << endl;
		for (int i = 0; i < amount; i++) {
			for (int i = 0; i < x; i++)
				cout << " ";
			if (i == counter)
				cout << changer << " " << menuFunctions[i][0] << endl;
			else
				cout << i + 1 << ". " << menuFunctions[i][0] << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int k = 0;
	menu m;

	m.SetNumberOfFunctions(0); // функция бесполезна т.к. переменная числа функций меняется динамически при объявлении нового элемента меню
	m.SetCoordinates(0, 0);
	m.SetPozition(1);
	m.SetColor(0, 14);
	m.SetChanger(" x");

	//объявление имен пунктов меню
	m.SetName(0, "Богомол");
	m.SetName(1, "Зебра");
	m.SetName(2, "Дракон");
	m.SetName(3, "Слоны");
	m.SetName(4, "Гепард");
	m.SetName(5, "Единорог");
	m.SetName(6, "");

	//объявление результата пункта
	m.SetMean(0, " Насекомое из семейства настоящих богомолов отряда богомоловых. Крупное хищное насекомое с приспособленными для хватания пищи передними конечностями. Достигает в длину 42—52 мм (самец) или 48—75 мм (самка). Наиболее крупный и самый распространённый вид богомолов в Европе.");
	m.SetMean(1, " Подрод рода лошади, включающий виды бурчеллова зебра, зебра Греви и горная зебра. Гибридные формы между зебрами и домашними лошадьми называют зеброидами, между зебрами и ослами — зебрулами. Зебры живут маленькими группами, состоящими из самок с детёнышами и одного жеребца.");
	m.SetMean(2, " Собирательное название, объединяющее ряд мифологических и фантастических существ. Дракон связан с христианским культом святого Георгия и получил широкое распространение в европейском религиозном искусстве.");
	m.SetMean(3, " Семейство млекопитающих отряда хоботных. В настоящее время к этому семейству относятся наиболее крупные наземные млекопитающие. Cамые крупные наземные животные на Земле. Обитают они в Юго-Восточной Азии и Африке в тропических лесах и саваннах.");
	m.SetMean(4, " Хищное млекопитающее семейства кошачьих, обитает в большинстве стран Африки, а также на Ближнем Востоке. Это единственный современный сохранившийся представитель рода Acinonyx. Быстрейший из всех наземных млекопитающих: за 3 секунды может развивать скорость до 110 км/ч");
	m.SetMean(5, " Мифическое существо, символизирует целомудрие, в широком смысле духовную чистоту и искания. Представляют его в виде коня c одним рогом, выходящим изо лба.");
	m.SetMean(6, "");
	//главный цикл. Демонстрация работоспособности класса
	do {
		system("cls");
		m.Print();
		m.Drop();
		k = _getch();
		m.Control(k);
		m.Move();
	} while (k != 27);

	return 0;
}