#include "number4.h"

char number4::IntToChar(int number) {
	switch (number) {
	case 0: return '0'; break;
	case 1: return '1'; break;
	case 2: return '2'; break;
	case 3: return '3'; break;
	case 4: return '4'; break;
	case 5: return '5'; break;
	case 6: return '6'; break;
	case 7: return '7'; break;
	case 8: return '8'; break;
	case 9: return '9'; break;
	default: return '0';
	}
}

int number4::CharToInt(char number) {
	switch (number) {
	case '0': return 0; break;
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	default: return 0;
	}
}

number4::number4() {}

number4::number4(int number) {
	int tmp = 0;
	if (number < 10)
		main[3] = IntToChar(number);
	if (number > 9 && number < 100) {
		main[3] = IntToChar(number % 10);
		main[2] = IntToChar(number / 10);
	}
	if (number > 99 && number < 1000) {
		main[3] = IntToChar(number % 10);
		main[2] = IntToChar((number % 100) / 10);
		main[1] = IntToChar(number / 100);
	}
	if (number > 999 && number < 10000) {
		main[3] = IntToChar(number % 10);
		main[2] = IntToChar((number % 100) / 10);
		main[1] = IntToChar((number % 1000) / 100);
		main[0] = IntToChar(number / 1000);
	}
}

number4::number4(std::string number) {
	for (int i = 0; i < 4; i++)
		main[i] = number[i];
}

int number4::ToInt() {
	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		tmp = tmp * 10 + CharToInt(this->main[i]);
	}
	return tmp;
}

number4 number4::operator+(int number) {
	number4 term = number;
	number4 tmp;
	int temp = 0;
	for (int i = 3; i >= 0; i--) {
		temp = CharToInt(this->main[i]) + CharToInt(term.main[i]) + temp;
		tmp.main[i] = IntToChar(temp % 10);
		temp /= 10;
	}
	return tmp;
}

number4 number4::operator-(int number) {
	number4 term = number;
	number4 tmp;
	int temp = 0;
	for (int i = 3; i >= 0; i--) {
		temp = CharToInt(this->main[i]) - CharToInt(term.main[i]) + temp;
		if (temp % 10 < 0)
			tmp.main[i] = IntToChar(10 + (temp % 10));
		else
			tmp.main[i] = IntToChar(temp % 10);
		temp /= 10;
	}
	return tmp;
}

number4 number4::operator+=(int number) {
	number4 term = number;
	int temp = 0;
	for (int i = 3; i >= 0; i--) {
		temp = CharToInt(this->main[i]) + CharToInt(term.main[i]) + temp;
		this->main[i] = IntToChar(temp % 10);
		temp /= 10;
	}
	return *this;
}

number4 number4::operator-=(int number) {
	number4 term = number;
	int temp = 0;
	for (int i = 3; i >= 0; i--) {
		temp = CharToInt(this->main[i]) - CharToInt(term.main[i]) + temp;
		if (temp % 10 < 0)
			this->main[i] = IntToChar(10 + (temp % 10));
		else
			this->main[i] = IntToChar(temp % 10);
		temp /= 10;
	}
	return *this;
}

number4 number4::operator=(std::string number) {
	for (int i = 0; i < 4; i++)
		this->main[i] = number[i];
	return *this;
}

number4 number4::operator=(number4 number) {
	for (int i = 0; i < 4; i++)
		this->main[i] = number.main[i];
	return *this;
}

number4 number4::operator=(int number) {
	number4 tmp = number;
	for (int i = 0; i < 4; i++)
		this->main[i] = tmp.main[i];
	return *this;
}

std::ostream& operator<<(std::ostream& cout, const number4& tmp) {
	for (int i = 0; i < 4; i++)
		cout << tmp.main[i];
	return cout;
}

number4::~number4() {
}
