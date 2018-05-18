#include "ProcessingÑenter.h"

ProcessingÑenter::ProcessingÑenter() {
	LoadFromFile();
}

void ProcessingÑenter::Working(int number) {
	if (client[number].deposite < 100000 && client[number].durable == 3)
		client[number].percent = 5;
	if (client[number].deposite < 100000 && client[number].durable == 6)
		client[number].percent = 6;
	if (client[number].deposite < 100000 && client[number].durable == 12)
		client[number].percent = 6;
	if (client[number].deposite < 100000 && client[number].durable == 24)
		client[number].percent = 6;
	if (client[number].deposite < 100000 && client[number].durable == 36)
		client[number].percent = 7;

	if (client[number].deposite < 500000 && client[number].deposite >= 100000 && client[number].durable == 3)
		client[number].percent = 6;
	if (client[number].deposite < 500000 && client[number].deposite >= 100000 && client[number].durable == 6)
		client[number].percent = 6;
	if (client[number].deposite < 500000 && client[number].deposite >= 100000 && client[number].durable == 12)
		client[number].percent = 6;
	if (client[number].deposite < 500000 && client[number].deposite >= 100000 && client[number].durable == 24)
		client[number].percent = 7;
	if (client[number].deposite < 500000 && client[number].deposite >= 100000 && client[number].durable == 36)
		client[number].percent = 7;

	if (client[number].deposite < 1000000 && client[number].deposite >= 500000 && client[number].durable == 3)
		client[number].percent = 7;
	if (client[number].deposite < 1000000 && client[number].deposite >= 500000 && client[number].durable == 6)
		client[number].percent = 7;
	if (client[number].deposite < 1000000 && client[number].deposite >= 500000 && client[number].durable == 12)
		client[number].percent = 7;
	if (client[number].deposite < 1000000 && client[number].deposite >= 500000 && client[number].durable == 24)
		client[number].percent = 8;
	if (client[number].deposite < 1000000 && client[number].deposite >= 500000 && client[number].durable == 36)
		client[number].percent = 8;

	if (client[number].deposite >= 1000000 && client[number].durable == 3)
		client[number].percent = 5;
	if (client[number].deposite >= 1000000 && client[number].durable == 6)
		client[number].percent = 6;
	if (client[number].deposite >= 1000000 && client[number].durable == 12)
		client[number].percent = 7;
	if (client[number].deposite >= 1000000 && client[number].durable == 24)
		client[number].percent = 8;
	if (client[number].deposite >= 1000000 && client[number].durable == 36)
		client[number].percent = 9;

	char month[10];
	char year[5];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	const char* format = "%d";
	strftime(month, 10, format, timeinfo);
	format = "%Y";
	strftime(year, 5, format, timeinfo);
	if (client[number].close.year == atoi(year)) {
		if (atoi(month) - client[number].close.month >= client[number].durable) {
			client[number].takeMoney += client[number].deposite * (client[number].percent / 12 * client[number].durable);
			client[number].opened = false;
		}
		else {
			client[number].takeMoney += client[number].deposite * (client[number].percent / 12 * (atoi(month) - client[number].open.month));
			client[number].opened = true;
		}
	}
	else {
		if (atoi(month) + 12 - client[number].close.month >= client[number].durable) {
			client[number].takeMoney += client[number].deposite * (client[number].percent / 12 * client[number].durable);
			client[number].opened = false;
		}
		else {
			client[number].takeMoney += client[number].deposite * (client[number].percent / 12 * (atoi(month) + 12 - client[number].open.month));
			client[number].opened = true;
		}
	}
}

int ProcessingÑenter::Month(std::string month) {
	if (month == "ßíâàğü") return 1;
	if (month == "Ôåâğàëü") return 2;
	if (month == "Ìàğò") return 3;
	if (month == "Àïğåëü") return 4;
	if (month == "Ìàé") return 5;
	if (month == "Èşíü") return 6;
	if (month == "Èşëü") return 7;
	if (month == "Àâãóñ") return 8;
	if (month == "Ñåíòÿáğü") return 9;
	if (month == "Îêòÿáğü") return 10;
	if (month == "Íîÿáğü") return 11;
	if (month == "Äåêàáğü") return 12;
}

void ProcessingÑenter::RegisterFromFile(number4 number, std::string _name, std::string _pass, int _money, int _day, int _month, int _year, int day, int month, int year, int deposite, double percent) {
	client[number.ToInt() - 1].info.number = number;
	client[number.ToInt() - 1].info.name = _name;
	client[number.ToInt() - 1].info.pass = _pass;
	client[number.ToInt() - 1].info.franklins = _money;
	client[number.ToInt() - 1].open.day = _day;
	client[number.ToInt() - 1].open.month = _month;
	client[number.ToInt() - 1].open.year = _year;
	client[number.ToInt() - 1].close.day = day;
	client[number.ToInt() - 1].close.month = month;
	client[number.ToInt() - 1].close.year = year;
	client[number.ToInt() - 1].deposite = deposite;
	client[number.ToInt() - 1].percent = percent;
	if (client[number.ToInt() - 1].open.year == client[number.ToInt() - 1].close.year)
		client[number.ToInt() - 1].durable = client[number.ToInt() - 1].close.month - client[number.ToInt() - 1].open.month;
	if (client[number.ToInt() - 1].open.year < client[number.ToInt() - 1].close.year) {
		if (client[number.ToInt() - 1].open.month - client[number.ToInt() - 1].close.month == 0)
			client[number.ToInt() - 1].durable = (client[number.ToInt() - 1].close.year - client[number.ToInt() - 1].open.year) * 12 * (client[number.ToInt() - 1].close.year - client[number.ToInt() - 1].open.year);
		if (client[number.ToInt() - 1].open.month - client[number.ToInt() - 1].close.month > 0)
			client[number.ToInt() - 1].durable = ((client[number.ToInt() - 1].open.month + 12) - client[number.ToInt() - 1].close.month) * 12 * (client[number.ToInt() - 1].close.year - client[number.ToInt() - 1].open.year);
		if (client[number.ToInt() - 1].open.month - client[number.ToInt() - 1].close.month < 0)
			client[number.ToInt() - 1].durable = (client[number.ToInt() - 1].close.month - client[number.ToInt() - 1].open.month) * 12 * (client[number.ToInt() - 1].close.year - client[number.ToInt() - 1].open.year);
	}
	Working(number.ToInt() - 1);
}

void ProcessingÑenter::LoadFromFile() {
	std::ifstream file("clients.txt");
	std::string str;
	std::string _name;
	std::string _pass;
	std::string tmp;
	int _day;
	int _month;
	int _year;
	int day;
	int month;
	int year;
	int deposite;
	double percent;
	int _money = 0;
	int counter = 0;
	if (!file) { return; }
	while (getline(file, str)) {
		while (1) {
			if (str[0] == '\n')
				break;
			if (str[0] == '\0')
				break;
			if (str[0] == 'n' && str[1] == 'u') {
				tmp = "";
				for (int i = 7; i < 11; i++)
					tmp += str[i];
				number = tmp;
				break;
			}
			if (str[0] == 'n' && str[1] == 'a') {
				counter = 5;
				_name = "";
				while (str[counter] != '\0')
					_name += str[counter++];
				break;
			}
			if (str[0] == 'p' && str[1] == 'a') {
				counter = 5;
				_pass = "";
				while (str[counter] != '\0')
					_pass += str[counter++];
				break;
			}
			if (str[0] == 'c' && str[1] == 'a') {
				counter = 5;
				tmp = "";
				while (str[counter] != '\0')
					tmp += str[counter++];
				_money = atoi(tmp.c_str());
				break;
			}
			if (str[0] == 'o') {
				counter = 5;
				tmp = "";
				while (str[counter] != ' ')
					tmp += str[counter++];
				_day = atoi(tmp.c_str());
				tmp = "";
				counter++;
				while (str[counter] != ' ')
					tmp += str[counter++];
				_month = atoi(tmp.c_str());
				tmp = "";
				counter++;
				while (str[counter] != '\0')
					tmp += str[counter++];
				_year = atoi(tmp.c_str());
				break;
			}
			if (str[0] == 'c' && str[1] == 'l') {
				counter = 6;
				tmp = "";
				while (str[counter] != ' ')
					tmp += str[counter++];
				day = atoi(tmp.c_str());
				tmp = "";
				counter++;
				while (str[counter] != ' ')
					tmp += str[counter++];
				month = atoi(tmp.c_str());
				tmp = "";
				counter++;
				while (str[counter] != '\0')
					tmp += str[counter++];
				year = atoi(tmp.c_str());
				break;
			}
			if (str[0] == 'd') {
				tmp = "";
				counter = 8;
				while (str[counter] != '\0')
					tmp += str[counter++];
				deposite = atoi(tmp.c_str());
				break;
			}
			if (str[0] == 'p' && str[1] == 'e') {
				tmp = "";
				counter = 8;
				while (str[counter] != '\0')
					tmp += str[counter++];
				percent = atoi(tmp.c_str());
				RegisterFromFile(number, _name, _pass, _money, _day, _month, _year, day, month, year, deposite, percent);
				break;
			}
		}
	}
	file.close();
}

ProcessingÑenter::~ProcessingÑenter() {
}