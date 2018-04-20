#include "Deposit.h"

Deposit::Deposit() {
}

bool Deposit::Authorization(number4 _number, std::string _pass) {
	if (client[_number.ToInt() - 1].info.pass == _pass) {
		currentUser = _number.ToInt() - 1;
		client[currentUser].access = true;
		Facilities();
		return true;
	}
	return false;
}

std::string Deposit::GetName() {
	return client[currentUser].info.name;
}

Processing—enter::Date Deposit::GetOpenDate() {
	return client[currentUser].open;
}

Processing—enter::Date Deposit::GetCloseDate() {
	return client[currentUser].close;
}

double Deposit::GetPercent() {
	return client[currentUser].percent;
}

int Deposit::GetMoney() {
	return client[currentUser].takeMoney;
}

number4 Deposit::GetNumber() {
	return number + 1;
}

bool Deposit::CheckDeposite() {
	if (client[currentUser].opened)
		return false;
	return true;
}

bool Deposit::CheckMoney(int money) {
	if (money <= client[currentUser].info.franklins)
		return true;
	return false;
}

bool Deposit::CheckDate(int date) {
	if (date == 3 || date == 6 || date == 12 || date == 24 || date == 36)
		return true;
	return false;
}

bool Deposit::CheckPassword(std::string pass) {
	if (pass.length() <= 3)
		return false;
	return true;
}

int Deposit::GetDeposit() {
	return client[currentUser].deposite;
}

int Deposit::GetCurrentMoney() {
	return client[currentUser].info.franklins;
}

void Deposit::Register(std::string _name, std::string _pass, int _money) {
	if (number.ToInt() > 9999)
		return;
	client[number.ToInt()].info.number = number + 1;
	client[number.ToInt()].info.name = _name;
	client[number.ToInt()].info.pass = _pass;
	client[number.ToInt()].info.franklins = _money;
}

void Deposit::OpenDeposit(int value, int money) {

	if (client[currentUser].opened)
		return;
	if (client[currentUser].info.franklins < money)
		return;
	else {
		char day[3];
		char month[10];
		char year[5];
		time_t seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);
		const char* format = "%B";
		strftime(month, 10, format, timeinfo);
		format = "%Y";
		strftime(year, 5, format, timeinfo);
		format = "%d";
		strftime(day, 3, format, timeinfo);

		client[currentUser].open.day = atoi(day);
		client[currentUser].open.month = Month(month);
		client[currentUser].open.year = atoi(year);

		if (Month(month) + value > 12) {
			client[currentUser].close.day = atoi(day);
			client[currentUser].close.month = Month(month) + value - 12;
			client[currentUser].close.year = atoi(year) + 1;
			for (int i = 0; i < 3; i++) {
				if (client[currentUser].close.month > 12) {
					client[currentUser].close.month -= 12;
					client[currentUser].close.year += 1;
				}
			}
		}
		else {
			client[currentUser].close.day = atoi(day);
			client[currentUser].close.month = Month(month) + value;
			client[currentUser].close.year = atoi(year);
		}


		if (client[currentUser].belov100 && money == 0)
			return;
		if (client[currentUser].belov500 && money > 500000)
			return;
		if (client[currentUser].belovMillion && money > 1000000)
			return;

		if (money < 100000 && value == 3)
			client[currentUser].percent = 5;
		if (money < 100000 && value == 6)
			client[currentUser].percent = 6;
		if (money < 100000 && value == 12)
			client[currentUser].percent = 6;
		if (money < 100000 && value == 24)
			client[currentUser].percent = 6;
		if (money < 100000 && value == 36)
			client[currentUser].percent = 7;

		if (money < 500000 && money >= 100000 && value == 3)
			client[currentUser].percent = 6;
		if (money < 500000 && money >= 100000 && value == 6)
			client[currentUser].percent = 6;
		if (money < 500000 && money >= 100000 && value == 12)
			client[currentUser].percent = 6;
		if (money < 500000 && money >= 100000 && value == 24)
			client[currentUser].percent = 7;
		if (money < 500000 && money >= 100000 && value == 36)
			client[currentUser].percent = 7;

		if (money < 1000000 && money >= 500000 && value == 3)
			client[currentUser].percent = 7;
		if (money < 1000000 && money >= 500000 && value == 6)
			client[currentUser].percent = 7;
		if (money < 1000000 && money >= 500000 && value == 12)
			client[currentUser].percent = 7;
		if (money < 1000000 && money >= 500000 && value == 24)
			client[currentUser].percent = 8;
		if (money < 1000000 && money >= 500000 && value == 36)
			client[currentUser].percent = 8;

		if (money >= 1000000 && value == 3)
			client[currentUser].percent = 5;
		if (money >= 1000000 && value == 6)
			client[currentUser].percent = 6;
		if (money >= 1000000 && value == 12)
			client[currentUser].percent = 7;
		if (money >= 1000000 && value == 24)
			client[currentUser].percent = 8;
		if (money >= 1000000 && value == 36)
			client[currentUser].percent = 9;

		client[currentUser].deposite = money;
		client[currentUser].info.franklins -= money;

		client[currentUser].opened = true;
	}
}

bool Deposit::TakeMoney() {
	if (client[currentUser].takeMoney > 0) {
		client[currentUser].info.franklins += client[currentUser].takeMoney;
		client[currentUser].takeMoney = 0;
		return true;
	}
	return false;
}

void Deposit::Save() {
	std::ofstream file("clients.txt");
	for (int i = 0; i <= number.ToInt(); i++) {
		if (client[i].info.number == number4(0))
			continue;
		file << "number:" << client[i].info.number << '\n';
		file << "name:" << client[i].info.name << '\n';
		file << "pass:" << client[i].info.pass << '\n';
		file << "cash:" << client[i].info.franklins << '\n';
		file << "open:" << client[i].open.day << " " << client[i].open.month << " " << client[i].open.year << "\n";
		file << "close:" << client[i].close.day << " " << client[i].close.month << " " << client[i].close.year << "\n";
		file << "deposit:" << client[i].deposite << "\n";
		file << "percent:" << client[i].percent << "\n";
		file << '\n';
	}
	file.close();

	if (file.eof())
		remove("clients.txt");
}

void Deposit::Facilities() {
	if (client[currentUser].access == true) {
		if (client[currentUser].info.franklins > 0)
			client[currentUser].belov100 = true;
		if (client[currentUser].info.franklins >= 100000)
			client[currentUser].belov500 = true;
		if (client[currentUser].info.franklins >= 500000)
			client[currentUser].belovMillion = true;
		if (client[currentUser].info.franklins >= 1000000)
			client[currentUser].aboveMillion = true;
	}
}

Deposit::~Deposit() {
	delete[] client;
}