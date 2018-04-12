#include "Deposit.h"

Deposit::Deposit() {
}

void Deposit::Authorization(number4 _number, std::string _pass) {
	if (client[_number.ToInt()].pass == _pass) {
		currentUser = _number.ToInt();
		client[currentUser].access = true;
		Facilities();
	}
}

void Deposit::Facilities() {
	if (client[currentUser].access == true) {
		if (client[currentUser].franklins > 0)
			client[currentUser].belov100 = true;
		if (client[currentUser].franklins >= 100000)
			client[currentUser].belov500 = true;
		if (client[currentUser].franklins >= 500000)
			client[currentUser].belovMillion = true;
		if (client[currentUser].franklins >= 1000000)
			client[currentUser].aboveMillion = true;
	}
}

Deposit::~Deposit() {
}
