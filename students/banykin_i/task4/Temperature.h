#pragma once
#include <iostream>
#include <string>
#include <fstream>

#define size 8760

using namespace std;

struct Date {
	int day;
	string month;
	int year;
	int hour;
	}
};

struct Temp {
	Date date;
	int temp;
};

class Temperature
{
	Date startDate;
	Temp temp[size] = {};
private:
	//переводит дату в часы
	int Conventer(int _hour, int _day, string _month) {
		if (_month == "january")
			return  (_day - 1) * 24 + _hour;
		if (_month == "february")
			return (_day - 1) * 24 + 31 * 24 + _hour;
		if (_month == "march")
			return (_day - 1) * 24 + 59 * 24 + _hour;
		if (_month == "april")
			return (_day - 1) * 24 + 90 * 24 + _hour;
		if (_month == "may")
			return (_day - 1) * 24 + 120 * 24 + _hour;
		if (_month == "june")
			return (_day - 1) * 24 + 151 * 24 + _hour;
		if (_month == "july")
			return (_day - 1) * 24 + 181 * 24 + _hour;
		if (_month == "august")
			return (_day - 1) * 24 + 212 * 24 + _hour;
		if (_month == "september")
			return (_day - 1) * 24 + 243 * 24 + _hour;
		if (_month == "october")
			return (_day - 1) * 24 + 273 * 24 + _hour;
		if (_month == "november")
			return (_day - 1) * 24 + 304 * 24 + _hour;
		if (_month == "december")
			return (_day - 1) * 24 + 334 * 24 + _hour;
	}
	//переводит строчное число в число integer
	int Number(char number) {
		switch (number) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		}
	}
	//инициализация
	void Init() {
		startDate.day = 0;
		startDate.hour = 0;
		startDate.month = "0m";
		startDate.year = 0;
	}
public:
	Temperature();

	void SetTemp(int _hour, int _day, string _month, int _year, int _temp);
	void Print();
	void Print(int _hour, int _day, string _month);
	void InputFile(string _name);
	void OutputFile(string _name);
	void SetStartDate(int _hour, int _day, string _month, int year);

	int ReturnMaxDay(string _month);
	int GetTemp(int _hour, int _day, string _month, int _year);
	int AvgTemp(int _hour1, int _day1, string _month1, int _hour2, int _day2, string _month2);
	int AvgTemp(string _month);
	int AvgTemp();
	int AvgTemp(string _time, string _month);

	string Month(int number);
	Date GetStartDate();

	~Temperature();
};