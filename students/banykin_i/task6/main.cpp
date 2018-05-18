#pragma comment(lib, "freeglut.lib")
//#include <iostream>
#include <GL/freeglut.h>

#include "Snake.h"
#include "Fruits.h"
#include "Manager.h"
#include "Map.h"

#define Width 640
#define Height 480
#define Step 20

Snake snake(Step);
Fruits fruit;
Manager mainGame;
Map field(Width, Height, Step);

int playerNumberOfMaxTail = 0;
int playerGameDelay = 0;

bool endless = false;//бесконечный режим
bool itCanBePressed = true;//запрещает нажимать несколько клавиш за 1 цикл

void SnakeBeginPosition() {
	for (int i = 0; i < snake.GetTail(); i++) {
		snake.SetCoordinates(i, 10 + i, 15);
	}
}

void StartMenu() {
	//показываем консоль
	mainGame.ShowConsole();
	system("cls");
	std::cout << "Tails For Win(" << snake.GetTail() + 5 << "min): ";
	std::cin >> playerNumberOfMaxTail;
	std::cout << "Game Delay: ";
	std::cin >> playerGameDelay;
	if (playerNumberOfMaxTail > 0 && playerNumberOfMaxTail < 15 || playerNumberOfMaxTail < 0)
		playerNumberOfMaxTail = 15;
	if (playerNumberOfMaxTail == 0)
		endless = true;
	if (playerGameDelay < 50)
		playerGameDelay = 50;
	//убираем консоль
	mainGame.HideConsole();
}

void ShowInformation() {
	//начало игры
	if (!mainGame.Gameover() && snake.GetDirection() == STAY) {
		char beginGame[50] = {};
		sprintf_s(beginGame, "Move To Start");
		mainGame.Text(beginGame, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1, Width / 2 - 100, Height / 2 + 200);
	}
	//проигрыш
	if (mainGame.Gameover() && !mainGame.Gamewin()) {
		char endGame[100] = {};
		char endScore[50] = {};
		char key[50] = {};
		sprintf_s(endGame, "WASTED");
		sprintf_s(endScore, "Your Score: %d", mainGame.GetScore());
		sprintf_s(key, "Press ENTER to try again");
		mainGame.Text(endGame, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1, Width / 2 - 70, Height / 2 + 20);
		mainGame.Text(endScore, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1, Width / 2 - 80, Height / 2 + 150);
		mainGame.Text(key, GLUT_BITMAP_9_BY_15, 1, 1, 1, Width - 250, 12);
	}
	//победа
	if (mainGame.Gamewin()) {
		char endScore[50] = {};
		char winGame[50] = {};
		char key[50] = {};
		sprintf_s(endScore, "Your Score: %d", mainGame.GetScore());
		sprintf_s(winGame, "You Win!");
		sprintf_s(key, "Press ENTER to try again");
		mainGame.Text(winGame, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1, Width / 2 - 70, Height / 2 + 20);
		mainGame.Text(endScore, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1, Width / 2 - 80, Height / 2 + 150);
		mainGame.Text(key, GLUT_BITMAP_9_BY_15, 1, 1, 1, Width - 250, 12);
	}
	//хвост в реальном времени
	if (!mainGame.Gameover() && !mainGame.Gamewin()) {
		char tail[50] = {};
		sprintf_s(tail, "Tail: %d", snake.GetTail());
		mainGame.Text(tail, GLUT_BITMAP_9_BY_15, 0, 0, 0, 1, Height - 12);
	}
	//счет в реальном времени
	if (!mainGame.Gameover() && !mainGame.Gamewin()) {
		char score[50] = {};
		sprintf_s(score, "Score: %d", mainGame.GetScore());
		mainGame.Text(score, GLUT_BITMAP_9_BY_15, 0, 0, 0, 1, Height - 25);
	}
	//осталось хвоста в реальном времмени
	if (!endless)
		if (!mainGame.Gameover() && !mainGame.Gamewin()) {
			char lessTail[50] = {};
			sprintf_s(lessTail, "Need: %d", snake.GetMaxTail() - snake.GetTail());
			mainGame.Text(lessTail, GLUT_BITMAP_9_BY_15, 0, 0, 0, 1, Height - 40);
		}
}

void RandomFruit() {
	fruit.Random(field.GetRight(), field.GetUp());
	for (int i = 0; i < snake.GetTail(); i++)
		if (fruit.GetX() == snake.GetX(i) && fruit.GetY() == snake.GetY(i))
			RandomFruit();
}

void Setup() {
	snake.SetTail(10);
	StartMenu();
	for (int i = 0; i < snake.GetTail(); i++)
		snake.SetCoordinates(i, Width / (Step * 2) - snake.GetTail() / 2 + i, Height / (Step * 2));
	mainGame.SetGameSpeed(playerGameDelay);
	mainGame.SetScore(0);
	mainGame.Start();
	snake.HeadColor(0, 0.5, 0);
	snake.TailColor(0, 1, 0);
	fruit.Color(255, 0, 0);
	field.Color(1, 1, 1);

	SnakeBeginPosition();
	RandomFruit();
	snake.MaxTail(playerNumberOfMaxTail);
	snake.Pause();
}

void Move() {
	//движение хвоста за головой
	for (int i = snake.GetTail(); i > 0; i--)
		snake.SetCoordinates(i, snake.GetX(i - 1), snake.GetY(i - 1));
	//движение головы
	switch (snake.GetDirection()) {
	case LEFT:snake.Left(); break;
	case RIGHT:snake.Right(); break;
	case UP:snake.Up(); break;
	case DOWN:snake.Down(); break;
	}
}

void WallsCollision() {
	//стенки
	if (snake.GetX(0) > field.GetRight() && snake.GetDirection() == RIGHT)
		mainGame.Lose();
	if (snake.GetX(0) < field.GetLeft() && snake.GetDirection() == LEFT)
		mainGame.Lose();
	if (snake.GetY(0) < field.GetDown() && snake.GetDirection() == DOWN)
		mainGame.Lose();
	if (snake.GetY(0) > field.GetUp() && snake.GetDirection() == UP)
		mainGame.Lose();
}

void FruitsCollision() {
	//фрукты
	if (fruit.Collision(snake.GetX(0), snake.GetY(0))) {
		mainGame.IncreaseScore(10);
		snake.IncreaseTail(1);
		RandomFruit();
	}
}

void TailCollision() {
	//хвост
	int lostTail;
	for (int i = snake.GetTail(); i > 0; i--) {
		if (snake.GetX(0) == snake.GetX(i) && snake.GetY(0) == snake.GetY(i)) {
			lostTail = (snake.GetTail() - i) * 10;
			snake.DecreaseTail(snake.GetTail() - i);
			mainGame.DecreaseScore(lostTail * 2);
		}
	}
}

void WinCheck() {
	if (endless == false)
		if (snake.GetTail() >= snake.GetMaxTail())
			mainGame.Win();
}

void Update() {
	Move();
	FruitsCollision();
	WallsCollision();
	TailCollision();
	WinCheck();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (!mainGame.Gameover() && !mainGame.Gamewin()) {
		field.Draw();
		snake.Draw();
		fruit.Draw(Step);
		itCanBePressed = true;
	}
	ShowInformation();
	glFlush();
	glutSwapBuffers();
}

void SpecialKeys(int key, int x, int y) {
	if (itCanBePressed) {
		switch (key) {
		case GLUT_KEY_LEFT: if (snake.GetDirection() != RIGHT) snake.SetDirection(LEFT); break;
		case GLUT_KEY_RIGHT: if (snake.GetDirection() != LEFT && snake.GetDirection() != STAY) snake.SetDirection(RIGHT); break;
		case GLUT_KEY_UP: if (snake.GetDirection() != DOWN) snake.SetDirection(UP); break;
		case GLUT_KEY_DOWN: if (snake.GetDirection() != UP) snake.SetDirection(DOWN); break;
		}
		itCanBePressed = false;
	}
}

void NormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 13: if (mainGame.Gameover() || mainGame.Gamewin())Setup(); break;
	case 27: glutDestroyWindow(1); break;
	}
}

void Timer(int) {
	display();
	if (snake.GetDirection() != STAY) {
		Update();
	}
	glutTimerFunc(mainGame.GetSpeed(), Timer, 0);
}

int main(int argc, char **argv) {
	Setup();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("SNAKE");
	glClearColor(0.2, 0.5, 0.8, 255);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Width, 0, Height);
	glutDisplayFunc(display);
	glutTimerFunc(1, Timer, 0);
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(NormalKeys);

	glutMainLoop();
}