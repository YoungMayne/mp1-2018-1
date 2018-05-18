#include "Fruits.h"

Fruits::Fruits() {
	srand(time(NULL));
}

void Fruits::Color(float red, float green, float blue) {
	R = red;
	G = green;
	B = blue;
}

void Fruits::Random(int valueX, int valueY) {
	fruit.x = 0 + rand() % valueX;
	fruit.y = 0 + rand() % valueY;
}

void Fruits::Draw(int scale) {
	glColor3f(R, G, B);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * 3.14; i += 3.14 / 128) {
		glVertex2f((fruit.x * scale + scale / 2) + (scale / 2 - 1) * sin(i), (fruit.y * scale + scale / 2) + (scale / 2 - 1) * cos(i));
	}
	glEnd();
}

bool Fruits::Collision(int x, int y) {
	if (x == fruit.x && y == fruit.y)
		return true;
	return false;
}

int Fruits::GetX() {
	return fruit.x;
}

int Fruits::GetY() {
	return fruit.y;
}

Fruits::~Fruits() {}