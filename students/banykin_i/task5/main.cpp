#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Clients.h"
#include "number4.h"
#include "Deposit.h"

using namespace std;

int main() {
	Clients c;
	c.Save();

	number4 dog = 34;
	dog -= 14;
	//number4 cat = dog - 15;
	cout << dog << endl;
	//cout << cat << endl;
	dog += 10;
	cout << dog << endl;
	string tmp = "9999";
	dog = tmp;
	dog -= 1;
	cout << dog << endl;

	system("pause");
	return 0;
}