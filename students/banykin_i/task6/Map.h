#pragma once
#include <GL/freeglut.h>

class Map {
	int height;
	int width;
	int step;

	int fieldR = 0;
	int fieldG = 0;
	int fieldB = 0;
public:
	Map(int Width, int Height, int scale);
	void Color(float red, float green, float blue);
	void Draw();
	int GetLeft();
	int GetDown();
	int GetUp();
	int GetRight();
	~Map();
};