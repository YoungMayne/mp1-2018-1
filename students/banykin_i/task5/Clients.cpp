#include "Clients.h"

Clients::Clients() {
	LoadFromFile();
	//for (int i = 0; i < size; i++) {
	//	number = i;
	//	client[i].number = number;
	//	client[i].name = "dog";
	//	client[i].pass = "sdfas";
	//	client[i].franklins = 1623476;
	//}
}

void Clients::RegisterFromFile(std::string _name, std::string _pass, int _money) {
	client[number.ToInt() - 1].number = number + 1;
	client[number.ToInt() - 1].name = _name;
	client[number.ToInt() - 1].pass = _pass;
	client[number.ToInt() - 1].franklins = _money;
}

void Clients::LoadFromFile() {
	std::ifstream file("clients.txt");
	std::string str;
	std::string _name;
	std::string _pass;
	std::string tmp;
	int _money = 0;
	int counter = 0;
	if (!file) { return; }
	while (getline(file, str)) {
		while (1) {
			if (str[0] == '\n')
				break;
			if (str[0] == '\0')
				break;
			if (str[0] == 'n' && str[1] == 'u') {
				tmp = "";
				for (int i = 7; i < 11; i++)
					tmp += str[i];
				number = tmp;
				break;
			}
			if (str[0] == 'n' && str[1] == 'a') {
				counter = 5;
				_name = "";
				while (str[counter] != '\0')
					_name += str[counter++];
				break;
			}
			if (str[0] == 'p') {
				counter = 5;
				_pass = "";
				while (str[counter] != '\0')
					_pass += str[counter++];
				break;
			}
			if (str[0] == 'c') {
				counter = 5;
				tmp = "";
				while (str[counter] != '\0')
					tmp += str[counter++];
				_money = atoi(tmp.c_str());
				RegisterFromFile(_name, _pass, _money);
				break;
			}
		}
	}
	for (int i = 0; i < number.ToInt(); i++)
		std::cout << client[i].name << std::endl;
	file.close();
}

void Clients::Register(std::string _name, std::string _pass, int _money) {
	for (int i = 0; i <= number.ToInt(); i++) {
		if (client[i].name == "deleted") {
			client[i].number = number;
			client[i].name = _name;
			client[i].pass = _pass;
			client[i].franklins = _money;
			return;
		}
	}
	client[number.ToInt() + 1].number = number;
	client[number.ToInt() + 1].name = _name;
	client[number.ToInt() + 1].pass = _pass;
	client[number.ToInt() + 1].franklins = _money;
}

void Clients::Save() {
	std::ofstream file("clients.txt");
	for (int i = 0; i < number.ToInt(); i++) {
		if (client[i].name == "deleted")
			file << "number:" << client[i].number + 1 << '\n';
		else {
			file << "number:" << client[i].number + 1 << '\n';
			file << "name:" << client[i].name << '\n';
			file << "pass:" << client[i].pass << '\n';
			file << "cash:" << client[i].franklins << '\n';
			file << '\n';
		}
	}
	file.close();
}

Clients::~Clients() {
	number = 0;
}
