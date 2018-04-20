#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

#include "number4.h"

class Processing—enter {
protected:
	number4 number = 0;
	struct Date {
		int day = 0;
		int month = 0;
		int year = 0;
	};
	struct CLIENTS {
		std::string name;
		std::string pass;
		number4 number;
		int franklins;
	};
	struct Facialities {
		CLIENTS info;
		Date open;
		Date close;
		int deposite = 0;
		int takeMoney = 0;
		double percent = 0;
		int durable = 0;
		bool opened = false;
		bool access = false;
		bool belov100 = false;
		bool belov500 = false;
		bool belovMillion = false;
		bool aboveMillion = false;
	}*client = new Facialities[9999];
	int Month(std::string month);
	void Working(int number);
	void RegisterFromFile(number4 number, std::string _name, std::string _pass, int _money, int _day, int _month, int _year, int day, int month, int year, int deposite, double percent);
	void LoadFromFile();
	Processing—enter();
	~Processing—enter();
};

