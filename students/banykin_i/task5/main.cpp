#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <ctime>

#include "number4.h"
#include "Deposit.h"
#include "menu.h"

using namespace std;

void Print() {
	Deposit c;
	menu m1;
	menu m2;

	m1.SetName("�����������");
	m1.SetName("�����������");
	m1.SetName("�����");

	m2.SetName("���������� � �����");
	m2.SetName("������� �������");
	m2.SetName("����� ��������");
	m2.SetName("�����");

	while (1) {
		m1.Start();
		if (m1.Choosen() == 0) {
			system("cls");
			string name;
			string pass;
			int money;
			cout << "���� ���: ";
			cin >> name;
			cout << "������� ������: ";
			cin >> pass;
			if (!c.CheckPassword(pass))
				cout << "������ ������ ���� ������� 3 ��������";
			else {
				cout << "����� �� ����� �����: ";
				cin >> money;
				c.Register(name, pass, money);
				cout << "��� �����: " << c.GetNumber() << endl;
			}
			_getch();
			system("cls");
		}
		if (m1.Choosen() == 1) {
			system("cls");
			string pass = "";
			int num = 0;
			cout << "��� �����: ";
			cin >> num;
			cout << "������� ������: ";
			cin >> pass;
			if (c.Authorization(num, pass) == true) {
				system("cls");
				while (1) {
					m2.Start();
					if (m2.Choosen() == 0) {
						system("cls");
						cout << "����� �����: " << c.GetNumber() << endl;
						cout << "���: " << c.GetName() << endl;
						cout << "����� �� �����: " << c.GetCurrentMoney() << endl;
						cout << "����� �� ��������: " << c.GetDeposit() << endl;
						cout << "������ ��������: " << c.GetOpenDate().day << " " << c.GetOpenDate().month << " " << c.GetOpenDate().year << endl;
						cout << "���� ��������: " << c.GetCloseDate().day << " " << c.GetCloseDate().month << " " << c.GetCloseDate().year << endl;
						cout << "��� �������: " << c.GetPercent() << " % ������� " << endl;
						cout << "����������: " << c.GetMoney() << endl;
						_getch();
						system("cls");
					}
					if (m2.Choosen() == 1) {
						system("cls");
						if (c.CheckDeposite()) {
							int money = 0;
							int value = 0;
							cout << "������� ����� ��������: ";
							cin >> money;
							if (!c.CheckMoney(money))
								cout << "������������ �������";
							else {
								cout << "������� ���� ��������(��������� ��������: 3 ������, 6 �������, 12 �������, 24 ������, 36 �������):  " << endl;
								cin >> value;
								if (c.CheckDate(value))
									c.OpenDeposit(value, money);
								else
									cout << "����� ����������� �� ����������" << endl;
							}
						}
						else
							cout << "������� ��� ����� \n������ ������ ���������� � ������ ���������� � �����" << endl;
						_getch();
						system("cls");
					}
					if (m2.Choosen() == 2) {
						if (c.TakeMoney())
							cout << "�������!";
						else
							cout << "������������ ������� �� �����";
						_getch();
						system("cls");
					}
					if (m2.Choosen() == 3) {
						c.Save();
						return;
					}
				}
			}
			else {
				system("cls");
				cout << "�������� �����/������" << endl;
				_getch();
			}
		}
		if (m1.Choosen() == 2) {
			c.Save();
			return;
		}
	}
	c.Save();
}

int main() {
	setlocale(LC_ALL, "Russian");

	Print();
	return 0;
}