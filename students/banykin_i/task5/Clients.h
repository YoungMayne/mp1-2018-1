#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "number4.h"

#define size 9999

class Clients {
	struct CLIENTS {
		std::string name;
		std::string pass;
		number4 number;
		int franklins;
		bool access = false;
		bool belov100 = false;
		bool belov500 = false;
		bool belovMillion = false;
		bool aboveMillion = false;
	};	
private:
	void RegisterFromFile(std::string _name, std::string _pass, int _money);
public:
	CLIENTS client[size];
	number4 number = 0;

	Clients();
	void Register(std::string _name, std::string _pass, int _money);
	void LoadFromFile();
	void Save();
	~Clients();
};

