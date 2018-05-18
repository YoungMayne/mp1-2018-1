#pragma once
#include <ctime>
#include <iostream>
#include <GL/freeglut.h>

class Fruits {
	struct {
		int x;
		int y;
	}fruit;
	float R = 0;
	float G = 0;
	float B = 0;
public:
	Fruits();
	void Random(int valueX, int valueY);
	void Color(float red, float green, float blue);
	void Draw(int scale);
	bool Collision(int x, int y);
	int GetX();
	int GetY();
	~Fruits();
};