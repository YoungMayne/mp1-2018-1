#include "Snake.h"

Snake::Snake(int Step) {
	step = Step;
}

void Snake::HeadColor(float red, float green, float blue) {
	headR = red;
	headG = green;
	headB = blue;
}

void Snake::TailColor(float red, float green, float blue) {
	tailR = red;
	tailG = green;
	tailB = blue;
}

void Snake::MaxTail(int value) {
	maxTail = value;
}

int Snake::GetMaxTail() {
	return maxTail;
}

void Snake::SetTail(int value) {
	snake.resize(value + 1);
}

void Snake::Pause() {
	dir = STAY;
}

void Snake::Draw() {
	glColor3f(headR, headG, headB);
	glRectf(snake[0].x * step, (snake[0].y * step), ((snake[0].x + 1) * step) - 1, ((snake[0].y + 1) * step) - 1);
	glColor3f(tailR, tailG, tailB);
	for (int i = 1; i < snake.size() - 1; i++)
		glRectf(snake[i].x * step, snake[i].y * step, ((snake[i].x + 1) * step) - 1, ((snake[i].y + 1) * step) - 1);
}

void Snake::Up() {
	snake[0].y++;
}

void Snake::Down() {
	snake[0].y--;
}

void Snake::Left() {
	snake[0].x--;
}

void Snake::Right() {
	snake[0].x++;
}

void Snake::IncreaseTail(int number) {
	snake.resize(snake.size() + number);
}

void Snake::DecreaseTail(int number) {
	snake.resize(snake.size() - number);
}

int Snake::GetDirection() {
	return dir;
}

int Snake::GetTail() {
	return snake.size() - 1;
}

int Snake::GetX(int number) {
	return snake[number].x;
}

int Snake::GetY(int number) {
	return snake[number].y;
}

void Snake::SetDirection(Direction number) {
	dir = number;
}

void Snake::SetCoordinates(int number, int x, int y) {
	snake[number].x = x;
	snake[number].y = y;
}

Snake::~Snake() {
	snake.clear();
}