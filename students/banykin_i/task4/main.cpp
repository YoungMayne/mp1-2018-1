#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <fstream>

#include "menu.h"
#include "Temperature.h"

//вместо system("cls") т.к. быстрее работает
void setcur(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//демонстрация работы
void Print() {
	Temperature t;
	menu m;
	menu M;

	m.DisableShowConsoleCursor();

	m.SetName(0, "Set Start Day");
	m.SetName(1, "Get Start Day");
	m.SetName(2, "Set Temperature");
	m.SetName(3, "Random Temperature");
	m.SetName(4, "Get Temperature");
	m.SetName(5, "Get Averange Temperature");
	m.SetName(6, "Load to file");
	m.SetName(7, "Load from file");
	m.SetName(8, "Print Year Temperature");
	m.SetName(9, "Exit");

	M.SetName(0, "Average FromDayToDay Temperature");
	M.SetName(1, "Average Month Temperature");
	M.SetName(2, "Average Year Temperature");
	M.SetName(3, "Average day/night Month Temperature");
	M.SetName(4, "Back");

	do {
		setcur(0, 0);
		m.Start();
		if (m.Choosen() == 1) {
			system("cls");
			int day; int hour; int year; string month;
			cout << "Enter hour: ";
			cin >> hour;
			system("cls");
			cout << "Enter day: ";
			cin >> day;
			system("cls");
			cout << "Enter month: ";
			cin >> month;
			system("cls");
			cout << "Enter year: ";
			cin >> year;
			system("cls");
			t.SetStartDate(hour, day, month, year);
			cout << "Deal" << endl;
			_getch();
			system("cls");
		}
		if (m.Choosen() == 2) {
			cout << t.GetStartDate().hour << "h " << t.GetStartDate().day << "d " << t.GetStartDate().month << " " << t.GetStartDate().year << "y ";
			_getch();
			system("cls");
		}
		if (m.Choosen() == 3) {
			system("cls");
			int day; int year; int hour; int temp;
			string month;
			cout << "Enter hour: ";
			cin >> hour;
			system("cls");
			cout << "Enter day: ";
			cin >> day;
			system("cls");
			cout << "Enter month: ";
			cin >> month;
			system("cls");
			cout << "Enter year: ";
			cin >> year;
			system("cls");
			cout << "Enter temperature: ";
			cin >> temp;
			system("cls");
			t.SetTemp(hour, day, month, year, temp);
			cout << "Deal" << endl;
			_getch();
			system("cls");
		}
		if (m.Choosen() == 4) {
			for (int i = 0; i < 12; i++) {
				for (int j = 1; j <= t.ReturnMaxDay(t.Month(i)); j++) {
					for (int k = 0; k < 24; k++) {
						t.SetTemp(k, j, t.Month(i), 2018, rand() % 50);
					}
				}
			}
			cout << "Deal" << endl;
			_getch();
			system("cls");
		}
		if (m.Choosen() == 5) {
			system("cls");
			int day; int year; int hour; int temp;
			string month;
			cout << "Enter hour: ";
			cin >> hour;
			system("cls");
			cout << "Enter day: ";
			cin >> day;
			system("cls");
			cout << "Enter month: ";
			cin >> month;
			system("cls");
			cout << "Enter year: ";
			cin >> year;
			system("cls");
			cout << t.GetTemp(hour, day, month, year) << endl;
			_getch();
			system("cls");
		}
		if (m.Choosen() == 6) {
			system("cls");
			do {
				setcur(0, 0);
				M.Start();
				if (M.Choosen() == 1) {
					int hour1; int day1; string month1; int hour2; int day2; string month2;
					cout << "Enter hour1 and hour2: ";
					cin >> hour1;
					cin >> hour2;
					system("cls");
					cout << "Enter day1 and day2: ";
					cin >> day1;
					cin >> day2;
					system("cls");
					cout << "Enter month1 and month2: ";
					cin >> month1;
					cin >> month2;
					system("cls");
					cout << t.AvgTemp(hour1, day1, month1, hour2, day2, month2) << endl;
					_getch();
					system("cls");
				}
				if (M.Choosen() == 2) {
					system("cls");
					string month;
					cout << "Enter month: ";
					cin >> month;
					system("cls");
					cout << t.AvgTemp(month) << endl;
					_getch();
					system("cls");
				}
				if (M.Choosen() == 3) {
					system("cls");
					cout << t.AvgTemp() << endl;
					_getch();
					system("cls");
				}
				if (M.Choosen() == 4) {
					system("cls");
					string day;
					string month;
					cout << "Enter day/night: ";
					cin >> day;
					system("cls");
					cout << "Enter month: ";
					cin >> month;
					system("cls");
					cout << t.AvgTemp(day, month) << endl;
					_getch();
					system("cls");
				}
				if (M.Choosen() == 5) {
					system("cls");
					break;
				}
			} while (1);
		}
		if (m.Choosen() == 7) {
			string name;
			system("cls");
			cout << "Enter The Name of File: ";
			cin >> name;
			name = name + ".txt";
			t.InputFile(name);
			cout << "Deal" << endl;
			_getch();
			system("cls");
		}
		if (m.Choosen() == 8) {
			string name;
			system("cls");
			cout << "Enter The Name of File: ";
			cin >> name;
			name = name + ".txt";
			t.OutputFile(name);
			cout << "Deal" << endl;
			_getch();
			system("cls");
		}
		if (m.Choosen() == 9) {
			system("cls");
			t.Print();
			_getch();
			system("cls");
		}
		if (m.Choosen() == 10) {
			system("cls");
			exit(1);
		}

	} while (1);
}

int main() {
	srand(time(NULL));	
	Print();

	return 0;
}