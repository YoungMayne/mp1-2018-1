#include <iostream>
#include <conio.h>
#include <Windows.h>

#define size 10

using namespace std;

class menu {
	const char* changer = " ";
	int counter = 0;
	int button = 0;
	int amount = 0;//���������� ������� � ����
	enum Direction { pressed, stay }dir = stay;
	const char* menuFunctions[size][size];//�������� ������ � ������� � ������������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//����� �����
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
	}background = Black, text = White;//����� �����
private:
	int x = 0;//���������� �� ����
	int y = 0;//�� ������
	 //������������� �������, ��� �� ������ �� �������� ���� �� ����� �����
	void initial() {
		for (int i = 0; i < size; i++)
			menuFunctions[0][i] = " ";
	}
public:
	menu() {
		initial();
	}
	//������ ��� ��������
	void SetChanger(const char* type) {
		changer = type;
	}
	//������������� ����� �������
	void SetNumberOfFunctions(int number) {
		amount = number;
	}
	//���������� ����� �������
	int GetNumberOfFunctions() {
		return amount;
	}
	//���� ��� ������
	void SetName(int number, const char* name) {
		menuFunctions[number][0] = name;
		amount++;
	}
	//���������� �������� �������
	const char* GetNameOfFunction(int number) {
		return menuFunctions[number][0];
	}
	//���� ������ �������� ��� �� ��������
	void SetMean(int number, const char* string) {
		menuFunctions[0][number + 1] = string;
	}
	//������ �������� ��� ��������
	const char* GetMeans(int number) {
		return menuFunctions[0][number + 1];
	}
	//������ ����������
	void SetCoordinates(int X, int Y) {
		x = X;
		y = Y;
	}
	//������ ��������� ������� ��������
	void SetPozition(int value) {
		counter = value - 1;
	}
	//���������� �������
	int GetPozition() {
		return counter;
	}
	//�������� "�� �����"
	void Move() {
		counter = (counter + amount) % (amount);
	}
	//������� ������� ����������
	void Control(int direction) {
		button = direction;
		if (button == 80)
			counter++;
		if (button == 72)
			counter--;
		if (button == 13)
			dir = pressed;
	}
	//������ �������� ���������� �������� ����
	void Drop() {
		if (dir == pressed) {
			for (int i = 0; i < x - 1; i++)
				cout << " ";
			cout << GetMeans(counter);
			dir = stay;
		}
	}
	//��������� ����� ���� � ������
	void SetColor(int bg, int txt) {
		background = Color(bg);
		text = Color(txt);
		SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
	}
	//����� �� ����� � ������ ���������
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

	m.SetNumberOfFunctions(0); // ������� ���������� �.�. ���������� ����� ������� �������� ����������� ��� ���������� ������ �������� ����
	m.SetCoordinates(0, 0);
	m.SetPozition(1);
	m.SetColor(0, 14);
	m.SetChanger(" x");

	//���������� ���� ������� ����
	m.SetName(0, "�������");
	m.SetName(1, "�����");
	m.SetName(2, "������");
	m.SetName(3, "�����");
	m.SetName(4, "������");
	m.SetName(5, "��������");
	m.SetName(6, "");

	//���������� ���������� ������
	m.SetMean(0, " ��������� �� ��������� ��������� ��������� ������ �����������. ������� ������ ��������� � ���������������� ��� �������� ���� ��������� ������������. ��������� � ����� 42�52 �� (�����) ��� 48�75 �� (�����). �������� ������� � ����� ��������������� ��� ��������� � ������.");
	m.SetMean(1, " ������ ���� ������, ���������� ���� ���������� �����, ����� ����� � ������ �����. ��������� ����� ����� ������� � ��������� �������� �������� ����������, ����� ������� � ������ � ���������. ����� ����� ���������� ��������, ���������� �� ����� � ��������� � ������ �������.");
	m.SetMean(2, " ������������� ��������, ������������ ��� �������������� � �������������� �������. ������ ������ � ������������ ������� ������� ������� � ������� ������� ��������������� � ����������� ����������� ���������.");
	m.SetMean(3, " ��������� ������������� ������ ��������. � ��������� ����� � ����� ��������� ��������� �������� ������� �������� �������������. C���� ������� �������� �������� �� �����. ������� ��� � ���-��������� ���� � ������ � ����������� ����� � ��������.");
	m.SetMean(4, " ������ ������������� ��������� ��������, ������� � ����������� ����� ������, � ����� �� ������� �������. ��� ������������ ����������� ������������� ������������� ���� Acinonyx. ���������� �� ���� �������� �������������: �� 3 ������� ����� ��������� �������� �� 110 ��/�");
	m.SetMean(5, " ���������� ��������, ������������� ����������, � ������� ������ �������� ������� � �������. ������������ ��� � ���� ���� c ����� �����, ��������� ��� ���.");
	m.SetMean(6, "");
	//������� ����. ������������ ����������������� ������
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