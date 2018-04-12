#pragma once
#include <iostream>

class number4
{
	char main[4] = { '0', '0', '0', '0' };
private:
	char IntToChar(int number);
	int CharToInt(char number);
public:
	number4();
	number4(int number);
	number4(std::string number);	
	number4 operator+(int number);
	number4 operator-(int number);
	number4 operator+=(int number);
	number4 operator-=(int number);
	number4 operator=(std::string number);
	number4 operator=(number4 number);
	number4 operator=(int number);
	int ToInt(); 
	friend std::ostream& operator<<(std::ostream& os, const number4& dt);
	~number4();
};

