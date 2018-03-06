#include <iostream>
#include <conio.h>

#define size 100

using namespace std;

class menu {
private:
	const char* menuFunctions[size][size];
	int amount = 0;//количество пунктов в меню
	int x = 0;//координата по иксу
	int y = 0;//по игреку
	void initial() {
		for (int i = 0; i < size; i++)
			menuFunctions[0][i] = " ";
	}
public:
	menu() {
		initial();
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
	//возвращает номер функции
	int GetFunction(int number) {
		menuFunctions[number];
		return number;
	}

	//вывод на экран
	void Print() {
		int counter = 0;
		int button = 0;
		do {
			system("cls");
			counter = (counter + amount + 1) % (amount + 1);
			for (int i = 0; i < y; i++)
				cout << endl;
			for (int i = 0; i <= amount; i++) {
				for (int i = 0; i < x; i++)
					cout << " ";
				if (i == counter)
					cout << ">> " << menuFunctions[i][0] << endl;
				else
					cout << i + 1 << ". " << menuFunctions[i][0] << endl;
			}
			for (int i = 0; i < x; i++)
				cout << " ";
			cout << endl << "Press ESC for exit" << endl;
			for (int i = 0; i < x; i++)
				cout << " ";
			if (button == 13) {
				cout << GetFunction(counter) + 1 << endl;
				cout << GetNameOfFunction(counter);
				cout << GetMeans(counter);
			}
			button = _getch();
			if (button == 80)
				counter++;
			if (button == 72)
				counter--;

		} while (button != 27);
	}
};

int main() {
	setlocale(LC_ALL, "Rus");

	menu m;

	m.SetNumberOfFunctions(5);
	m.SetCoordinates(0, 0);
	m.SetName(0, "Богомол");
	m.SetName(1, "Зебра");
	m.SetName(2, "Дракон");
	m.SetName(3, "Слоны");
	m.SetName(4, "Гепард");
	m.SetName(5, "Единорог");

	m.SetMean(0, " насекомое из семейства настоящих богомолов отряда богомоловых. Крупное хищное насекомое с приспособленными для хватания пищи передними конечностями. Достигает в длину 42—52 мм (самец) или 48—75 мм (самка). Наиболее крупный и самый распространённый вид богомолов в Европе.");
	m.SetMean(1, " подрод рода лошади, включающий виды бурчеллова зебра, зебра Греви и горная зебра. Гибридные формы между зебрами и домашними лошадьми называют зеброидами, между зебрами и ослами — зебрулами. Зебры живут маленькими группами, состоящими из самок с детёнышами и одного жеребца.");
	m.SetMean(2, " собирательное название, объединяющее ряд мифологических и фантастических существ. Дракон связан с христианским культом святого Георгия и получил широкое распространение в европейском религиозном искусстве.");
	m.SetMean(3, " семейство млекопитающих отряда хоботных. В настоящее время к этому семейству относятся наиболее крупные наземные млекопитающие. Cамые крупные наземные животные на Земле. Обитают они в Юго-Восточной Азии и Африке в тропических лесах и саваннах.");
	m.SetMean(4, " хищное млекопитающее семейства кошачьих, обитает в большинстве стран Африки, а также на Ближнем Востоке. Это единственный современный сохранившийся представитель рода Acinonyx. Быстрейший из всех наземных млекопитающих: за 3 секунды может развивать скорость до 110 км/ч");
	m.SetMean(5, " мифическое существо, символизирует целомудрие, в широком смысле духовную чистоту и искания. Представляют его в виде коня c одним рогом, выходящим изо лба.");
	m.Print();

	return 0;
}