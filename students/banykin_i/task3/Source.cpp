#include <iostream>
#include <conio.h>

#define size 100

using namespace std;

class menu {
private:
	const char* menuFunctions[size][size];
	int amount = 0;//���������� ������� � ����
	int x = 0;//���������� �� ����
	int y = 0;//�� ������
	void initial() {
		for (int i = 0; i < size; i++)
			menuFunctions[0][i] = " ";
	}
public:
	menu() {
		initial();
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
	//���������� ����� �������
	int GetFunction(int number) {
		menuFunctions[number];
		return number;
	}

	//����� �� �����
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
	m.SetName(0, "�������");
	m.SetName(1, "�����");
	m.SetName(2, "������");
	m.SetName(3, "�����");
	m.SetName(4, "������");
	m.SetName(5, "��������");

	m.SetMean(0, " ��������� �� ��������� ��������� ��������� ������ �����������. ������� ������ ��������� � ���������������� ��� �������� ���� ��������� ������������. ��������� � ����� 42�52 �� (�����) ��� 48�75 �� (�����). �������� ������� � ����� ��������������� ��� ��������� � ������.");
	m.SetMean(1, " ������ ���� ������, ���������� ���� ���������� �����, ����� ����� � ������ �����. ��������� ����� ����� ������� � ��������� �������� �������� ����������, ����� ������� � ������ � ���������. ����� ����� ���������� ��������, ���������� �� ����� � ��������� � ������ �������.");
	m.SetMean(2, " ������������� ��������, ������������ ��� �������������� � �������������� �������. ������ ������ � ������������ ������� ������� ������� � ������� ������� ��������������� � ����������� ����������� ���������.");
	m.SetMean(3, " ��������� ������������� ������ ��������. � ��������� ����� � ����� ��������� ��������� �������� ������� �������� �������������. C���� ������� �������� �������� �� �����. ������� ��� � ���-��������� ���� � ������ � ����������� ����� � ��������.");
	m.SetMean(4, " ������ ������������� ��������� ��������, ������� � ����������� ����� ������, � ����� �� ������� �������. ��� ������������ ����������� ������������� ������������� ���� Acinonyx. ���������� �� ���� �������� �������������: �� 3 ������� ����� ��������� �������� �� 110 ��/�");
	m.SetMean(5, " ���������� ��������, ������������� ����������, � ������� ������ �������� ������� � �������. ������������ ��� � ���� ���� c ����� �����, ��������� ��� ���.");
	m.Print();

	return 0;
}