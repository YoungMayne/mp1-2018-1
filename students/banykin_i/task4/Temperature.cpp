#include "Temperature.h"

//возвращает мес¤ц по номеру
string Temperature::Month(int number) {
	switch (number) {
	case 0: return "january"; break;
	case 1: return "february"; break;
	case 2: return "march"; break;
	case 3: return "april"; break;
	case 4: return "may"; break;
	case 5: return "june"; break;
	case 6: return "july"; break;
	case 7: return "august"; break;
	case 8: return "september"; break;
	case 9: return "october"; break;
	case 10: return "november"; break;
	case 11: return "december"; break;
	}
}

Temperature::Temperature(){
	Init();
}

//задать начало отсчета температуры
void Temperature::SetStartDate(int _hour, int _day, string _month, int _year) {
	startDate.day = _day;
	startDate.month = _month;
	startDate.year = _year;
	startDate.hour = _hour;
}

Date Temperature::GetStartDate() {
	return startDate;
}

//задать температуру выбраного числа
void Temperature::SetTemp(int _hour, int _day, string _month, int _year, int _temp) {
	temp[Conventer(_hour, _day, _month)].date.day = _day;
	temp[Conventer(_hour, _day, _month)].date.month = _month;
	temp[Conventer(_hour, _day, _month)].date.year = _year;
	temp[Conventer(_hour, _day, _month)].date.hour = _hour;
	temp[Conventer(_hour, _day, _month)].temp = _temp;
}
//возвращает последнее число мес§ца
int Temperature::ReturnMaxDay(string _month) {
	if (_month == "january")
		return 31;
	if (_month == "february")
		return 28;
	if (_month == "march")
		return 31;
	if (_month == "april")
		return 30;
	if (_month == "may")
		return 31;
	if (_month == "june")
		return 30;
	if (_month == "july")
		return 31;
	if (_month == "august")
		return 31;
	if (_month == "september")
		return 30;
	if (_month == "october")
		return 31;
	if (_month == "november")
		return 30;
	if (_month == "december")
		return 31;
}
//получить темпертуру выбранного числа
int Temperature::GetTemp(int _hour, int _day, string _month, int _year) {
	return temp[Conventer(_hour, _day, _month)].temp;
}
//вывести весь массив в консоль
void Temperature::Print() {
	for (int i = 0; i < size; i++) {
		if (temp[i].date.day == 0)
			continue;
		else
			cout << temp[i].date.day << "d " << temp[i].date.month << " " << temp[i].date.year << "y " << temp[i].date.hour << "h : " << temp[i].temp << endl;
	}
}
//вывести определенную §чейку в консоль
void Temperature::Print(int _hour, int _day, string _month) {
	cout << temp[Conventer(_hour, _day, _month)].date.day << "d " << temp[Conventer(_hour, _day, _month)].date.month << " " << temp[Conventer(_hour, _day, _month)].date.year << "y " << temp[Conventer(_hour, _day, _month)].date.hour << "h : " << temp[Conventer(_hour, _day, _month)].temp << endl;
}
//средн§§ температура от выбранной даты до выбранной даты
int Temperature::AvgTemp(int _hour1, int _day1, string _month1, int _hour2, int _day2, string _month2) {
	int tmp = 0;
	int count = 0;
	for (int i = Conventer(_hour1, _day1, _month1); i < Conventer(_hour2, _day2, _month2); i++) {
		if (temp[i].date.day == 0)
			continue;
		else {
			tmp += temp[i].temp;
			count++;
		}
	}
	if (count == 0)
		return 0;
	else
		return tmp / count;
}
//средн§§ температура мес§ца
int Temperature::AvgTemp(string _month) {
	int tmp = 0;
	int count = 0;
	for (int i = Conventer(0, 1, _month); i < Conventer(23, ReturnMaxDay(_month), _month); i++) {
		if (temp[i].date.day == 0)
			continue;
		else {
			tmp += temp[i].temp;
			count++;
		}
	}
	if (count == 0)
		return 0;
	else
		return tmp / count;
}
//средн§§ температура всего массива
int Temperature::AvgTemp() {
	int tmp = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (temp[i].date.day == 0)
			continue;
		else {
			tmp += temp[i].temp;
			count++;
		}
	}
	if (count == 0)
		return 0;
	else
		return tmp / count;
}
//средна§§ температура дн§/ночи мес§ца
int Temperature::AvgTemp(string _time, string _month) {
	int tmp = 0;
	int count = 0;
	if (_time == "day") {
		for (int i = 1; i <= ReturnMaxDay(_month); i++) {
			for (int j = 12; j <= 23; j++) {
				if (temp[Conventer(j, i, _month)].date.day == 0)
					continue;
				else {
					tmp += temp[Conventer(j, i, _month)].temp;
					count++;
				}
			}
		}
		if (count == 0)
			return 0;
		else
			return tmp / count;
	}
	if (_time == "night") {
		for (int i = 1; i <= ReturnMaxDay(_month); i++) {
			for (int j = 0; j <= 12; j++) {
				if (temp[Conventer(j, i, _month)].date.day == 0)
					continue;
				else {
					tmp += temp[Conventer(j, i, _month)].temp;
					count++;
				}
			}
		}
		if (count == 0)
			return 0;
		else
			return tmp / count;
	}
}
//занести данные в текстовый файл
void Temperature::InputFile(string _name) {
	ofstream file;
	file.open(_name);
	for (int i = 0; i < size; i++) {
		if (temp[i].date.day == 0)
			continue;
		else
			file << temp[i].date.day << "d " << temp[i].date.month << " " << temp[i].date.year << "y " << temp[i].date.hour << "h : " << temp[i].temp << 'C' << '\n';
	}
	file.close();
}
//занести данные из текстового файла в массив 
void Temperature::OutputFile(string _name) {
	int d;
	char m[15] = {};
	int y;
	int h;
	int t;
	int c = 0;
	int _c = 0;
	string str;
	ifstream file;
	file.open(_name);
	if (!file)
	{
		cout << "Error! File is not founded " << endl;
		return;
	}
	else {
		while (getline(file, str)) {
			for (int i = 0; i < 100; i++) {
				if (str[i] == 'C') {
					SetTemp(h, d, m, y, t);
					break;
				}
				if (str[i] == 'd') {
					d = 0;
					if (i == 1)
						d = Number(str[0]);
					if (i == 2)
						d = Number(str[0]) * 10 + Number(str[1]);
				}

				if (str[i] == ' ') {
					if (i == 2) {
						for (int o = 0; o < 15; o++) m[o] = {};
						c = 3;
						_c = 0;
						while (str[c] != ' ') {
							m[_c] = str[c];
							_c++; c++;
						}
					}
					if (i == 3) {
						for (int o = 0; o < 15; o++) m[o] = {};
						c = 4;
						_c = 0;
						while (str[c] != ' ') {
							m[_c] = str[c];
							_c++; c++;
						}
					}
				}
				if (str[i] == 'y' && str[i - 1] != 'r' && str[i - 1] != 'a' && str[i - 1] != 'l') {
					c = i - 4;
					y = 0;
					while (str[c] != 'y') {
						y = y * 10 + Number(str[c]);
						c++;
					}
				}
				if (str[i] == 'h') {
					h = 0;
					if (str[i - 2] == ' ')
						h = Number(str[i - 1]);
					if (str[i - 3] == ' ')
						h = Number(str[i - 2]) * 10 + Number(str[i - 1]);
				}
				if (str[i] == ':') {
					c = i + 2;
					t = 0;
					while (str[c] != 'C') {
						t = t * 10 + Number(str[c]);
						c++;
					}
				}

			}
		}
	}
	file.close();
}

Temperature::~Temperature(){}
