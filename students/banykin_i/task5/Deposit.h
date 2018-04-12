#pragma once
#include <iostream>
#include "number4.h"
#include "Clients.h"

class Deposit : public Clients {
	int currentUser = 0;
public:
	Deposit();
	void Authorization(number4 _number, std::string _pass);
	void Facilities();
	~Deposit();
};

