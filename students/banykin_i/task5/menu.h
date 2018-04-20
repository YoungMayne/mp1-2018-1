#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

class menu
{
	std::string menuFunctions[10];
	std::string changer = ">> ";
	int counter = 0;
	int amount = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pozition;
	bool isPressed = false;
private:
	void SetCoordinates(int x, int y);
	void DisableShowConsoleCursor();
public:
	menu();
	void SetName(std::string name);
	void Control();
	int Choosen();
	void Start();
};

