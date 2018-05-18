#include "Manager.h"

Manager::Manager() {}

void Manager::IncreaseScore(int number) {
	score += number;
}

void Manager::HideConsole() {
	AllocConsole();
	Hide = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Hide, 0);
}

void Manager::ShowConsole() {
	AllocConsole();
	Hide = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Hide, 1);
}

void Manager::DecreaseScore(int number) {
	score -= number;
}

int Manager::GetScore() {
	if (score < 0)
		score = 0;
	return score;
}

void Manager::SetScore(int value) {
	score = value;
}

void Manager::SetGameSpeed(int Speed) {
	speed = Speed;
}

int Manager::GetSpeed() {
	return speed;
}

void Manager::Lose() {
	gameover = true;
}

void Manager::Start() {
	gameover = false;
	win = false;
}

bool Manager::Gameover() {
	return gameover;
}

bool Manager::Gamewin() {
	return win;
}

void Manager::Win() {
	win = true;
}

void Manager::Text(char text[], void* font, int red, int green, int blue, int x, int y) {
	glColor3f(red, green, blue);
	glRasterPos2f(x, y);
	for (int i = 0; i < 50; i++) {
		glutBitmapCharacter(font, (int)text[i]);
	}
}

Manager::~Manager() {}