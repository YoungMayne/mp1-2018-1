#pragma once
#include <GL/freeglut.h>
#include <iostream>

class Manager {
	int score = 0;
	bool gameover = false;
	bool win = false;
	int speed = 0;
	HWND Hide;
public:
	Manager();
	void IncreaseScore(int number);
	void DecreaseScore(int number);
	void HideConsole();
	void ShowConsole();
	int GetScore();
	void SetScore(int value);
	void SetGameSpeed(int Speed);
	int GetSpeed();
	void Lose();
	void Start();
	void Text(char text[], void* font, int red, int green, int blue, int x, int y);
	bool Gameover();
	bool Gamewin();
	void Win();
	~Manager();
};