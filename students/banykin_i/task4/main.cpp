#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

#define size 8761
using namespace std;

//функци¤ не относ¤ща¤с¤ к заданию, нужна дл¤ заполнени¤ массива
string Month(int number) {
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

class Temperature {
	struct Date {
		int day;
		string month;
		int year;
		int hour;
	};

	struct Temp {
		Date date;
		int temp;
	}temp[size] = {};
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
public:
	//задать температуру выбраного числа
	void SetTemp(int _hour, int _day, string _month, int _year, int _temp) {
		temp[Conventer(_hour, _day, _month)].date.day = _day;
		temp[Conventer(_hour, _day, _month)].date.month = _month;
		temp[Conventer(_hour, _day, _month)].date.year = _year;
		temp[Conventer(_hour, _day, _month)].date.hour = _hour;
		temp[Conventer(_hour, _day, _month)].temp = _temp;
	}
	//возвращает последнее число мес¤ца
	int ReturnMaxDay(string _month) {
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
	int GetTemp(int _hour, int _day, string _month) {
		return temp[Conventer(_hour, _day, _month)].temp;
	}
	//вывести весь массив в консоль
	void Print() {
		for (int i = 0; i < size; i++) {
			if (temp[i].date.day == 0)
				continue;
			else
				cout << i << " " << temp[i].date.day << "d " << temp[i].date.month << " " << temp[i].date.year << "y " << temp[i].date.hour << "h : " << temp[i].temp << endl;
		}
	}
	//вывести определенную ¤чейку в консоль
	void Print(int _hour, int _day, string _month) {
		cout << temp[Conventer(_hour, _day, _month)].date.day << "d " << temp[Conventer(_hour, _day, _month)].date.month << " " << temp[Conventer(_hour, _day, _month)].date.year << "y " << temp[Conventer(_hour, _day, _month)].date.hour << "h : " << temp[Conventer(_hour, _day, _month)].temp << endl;
	}
	//средн¤¤ температура от выбранной даты до выбранной даты
	int AvgTemp(int _hour1, int _day1, string _month1, int _hour2, int _day2, string _month2) {
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
		return tmp / count;
	}
	//средн¤¤ температура мес¤ца
	int AvgTemp(string _month) {
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
		return tmp / count;
	}
	//средн¤¤ температура всего массива
	int AvgTemp() {
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
		return tmp / count;
	}
	//средна¤¤ температура дн¤/ночи мес¤ца
	int AvgTemp(string _time, string _month) {
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
			return tmp / count;
		}
	}
	//занести данные в текстовый файл
	void InputFile(string _name) {
		ofstream file(_name);
		for (int i = 0; i < size; i++) {
			if (temp[i].date.day == 0)
				continue;
			else
				file << temp[i].date.day << "d " << temp[i].date.month << " " << temp[i].date.year << "y " << temp[i].date.hour << "h : " << temp[i].temp << 'C' << '\n';
		}
		file.close();
	}
	//занести данные из текстового файла в массив 
	void OutputFile(string _name) {
		int d;
		char m[15] = {};
		int y;
		int h;
		int t;
		int c = 0;
		int _c = 0;
		string str;
		ifstream file(_name);
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
		file.close();
	}
};

int main() {
	Temperature t;

	srand(time(NULL));
	//заполн¤ет массив случайной температурой
	for (int i = 0; i < 12; i++) {
		for (int j = 1; j <= t.ReturnMaxDay(Month(i)); j++) {
			for (int k = 0; k < 24; k++) {
				t.SetTemp(k, j, Month(i), 2018, rand() % 10000);
			}
		}
	}
	//t.Print();
	//cout << endl;
	//cout << t.AvgTemp(0, 1, "january", 23, 31, "july") << endl;
	//cout << t.AvgTemp("february") << endl;
	//cout << t.AvgTemp() << endl;
	//cout << t.AvgTemp("day", "july") << endl;
	//cout << t.AvgTemp("night", "april") << endl;
	t.InputFile("TEMP.txt");
	t.OutputFile("TEMP.txt");
	t.Print();

	system("pause");
	return 0;
}