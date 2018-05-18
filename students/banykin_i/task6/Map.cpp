#include "Map.h"

Map::Map(int Width, int Heigth, int Step) {
	height = Heigth;
	width = Width;
	step = Step;
}

void Map::Color(float red, float green, float blue) {
	fieldR = red;
	fieldG = green;
	fieldB = blue;
}

void Map::Draw() {
	glColor3f(fieldR, fieldG, fieldB);
	glBegin(GL_LINES);
	for (int i = 0; i < width; i += step) {
		glVertex2i(i, height);
		glVertex2i(i, 0);
	}
	for (int i = 0; i < height; i += step) {
		glVertex2i(0, i);
		glVertex2i(width, i);
	}
	glEnd();
}

int Map::GetLeft() {
	return 0;
}
int Map::GetDown() {
	return 0;
}
int Map::GetUp() {
	return (height - step) / step;
}
int Map::GetRight() {
	return (width - step) / step;
}

Map::~Map() {}