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

	m1.SetName("Регистрация");
	m1.SetName("Авторизация");
	m1.SetName("Выйти");

	m2.SetName("Информация о счете");
	m2.SetName("Открыть депозит");
	m2.SetName("Снять проценты");
	m2.SetName("Выйти");

	while (1) {
		m1.Start();
		if (m1.Choosen() == 0) {
			system("cls");
			string name;
			string pass;
			int money;
			cout << "Ваше имя: ";
			cin >> name;
			cout << "Введите пароль: ";
			cin >> pass;
			if (!c.CheckPassword(pass))
				cout << "Пароль должен быть длиннее 3 символов";
			else {
				cout << "Сумма на вашем счету: ";
				cin >> money;
				c.Register(name, pass, money);
				cout << "Ваш номер: " << c.GetNumber() << endl;
			}
			_getch();
			system("cls");
		}
		if (m1.Choosen() == 1) {
			system("cls");
			string pass = "";
			int num = 0;
			cout << "Ваш номер: ";
			cin >> num;
			cout << "Введите пароль: ";
			cin >> pass;
			if (c.Authorization(num, pass) == true) {
				system("cls");
				while (1) {
					m2.Start();
					if (m2.Choosen() == 0) {
						system("cls");
						cout << "Номер счета: " << c.GetNumber() << endl;
						cout << "Имя: " << c.GetName() << endl;
						cout << "Денег на счету: " << c.GetCurrentMoney() << endl;
						cout << "Денег на депозите: " << c.GetDeposit() << endl;
						cout << "Начало депозита: " << c.GetOpenDate().day << " " << c.GetOpenDate().month << " " << c.GetOpenDate().year << endl;
						cout << "Срок депозита: " << c.GetCloseDate().day << " " << c.GetCloseDate().month << " " << c.GetCloseDate().year << endl;
						cout << "Под процент: " << c.GetPercent() << " % годовых " << endl;
						cout << "Накопилось: " << c.GetMoney() << endl;
						_getch();
						system("cls");
					}
					if (m2.Choosen() == 1) {
						system("cls");
						if (c.CheckDeposite()) {
							int money = 0;
							int value = 0;
							cout << "Введите сумму депозита: ";
							cin >> money;
							if (!c.CheckMoney(money))
								cout << "Недостаточно средств";
							else {
								cout << "Введите срок депозита(Возможные варианты: 3 месяца, 6 месяцев, 12 месяцев, 24 месяца, 36 месяцев):  " << endl;
								cin >> value;
								if (c.CheckDate(value))
									c.OpenDeposit(value, money);
								else
									cout << "Такой возможности не существует" << endl;
							}
						}
						else
							cout << "Депозит уже отрыт \nМожете узнать информацию в пункте Информация о счете" << endl;
						_getch();
						system("cls");
					}
					if (m2.Choosen() == 2) {
						if (c.TakeMoney())
							cout << "Успешно!";
						else
							cout << "Недостаточно средств на счете";
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
				cout << "Неверный номер/пароль" << endl;
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