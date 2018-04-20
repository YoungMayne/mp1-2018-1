#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>

#include "number4.h"
#include "Processing—enter.h"

class Deposit : public Processing—enter {
	int currentUser = 0;
public:
	Deposit();
	void Register(std::string _name, std::string _pass, int _money);
	bool Authorization(number4 _number, std::string _pass);
	number4 GetNumber();
	std::string GetName();
	Date GetOpenDate();
	Date GetCloseDate();
	double GetPercent();
	int GetMoney();
	int GetDeposit();
	int GetCurrentMoney();
	bool CheckDeposite();
	bool CheckMoney(int money);
	bool CheckDate(int date);
	bool CheckPassword(std::string pass);
	void Save();
	void Facilities();
	void OpenDeposit(int value, int money);
	bool TakeMoney();
	~Deposit();
};

