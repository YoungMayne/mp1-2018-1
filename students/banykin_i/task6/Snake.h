#pragma once
#include <GL/freeglut.h>
#include <vector>

enum Direction { STAY, LEFT, RIGHT, UP, DOWN };

class Snake {
	struct S {
		int x;
		int y;
	};
	std::vector<S>snake;
	Direction dir = STAY;
	float headR = 0;
	float headG = 0;
	float headB = 0;
	float tailR = 0;
	float tailG = 0;
	float tailB = 0;
	int step;
	int maxTail = 100;
public:
	Snake(int Step);
	void HeadColor(float red, float green, float blue);
	void TailColor(float red, float green, float blue);
	void MaxTail(int value);
	int GetMaxTail();
	void Draw();
	void Pause();
	void SetTail(int value);
	int GetDirection();
	void IncreaseTail(int number);
	void DecreaseTail(int number);
	void Up();
	void Down();
	void Left();
	void Right();
	void SetDirection(Direction number);
	void SetCoordinates(int number, int x, int y);
	int GetTail();
	int GetX(int number);
	int GetY(int number);
	~Snake();
};