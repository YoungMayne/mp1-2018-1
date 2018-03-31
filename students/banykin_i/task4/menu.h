#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>

#define size 50

using namespace std;

class menu
{
	string menuFunctions[size];
	int counter = 0;//переменная , двигающая ползунок
	int amount = 0;//количество пунктов в меню
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool isPressed = false;
private:
	void Init() {
		amount = 0;
		for (int i = 0; i < size; i++)
			menuFunctions[i] = " ";
	}
public:
	menu();
	~menu();
	void Control();
	void SetName(int number, string name);
	void DisableShowConsoleCursor();
	int Choosen();
	void Start();
};