#include "Life.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

int** Life::inicSpace(int x, int y)
{
	spaceX = x;
	spaceY = y;
	//adding a contour 
	A = spaceX + 2;
	B = spaceY + 2;
	int** space = new int* [A];
	for (int i = 0; i < A; i++) {
		space[i] = new int[B];
	}
	return space;
}

Life::Life(int X, int Y)
{
	space = inicSpace(X, Y);
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			space[i][j] = 0;
		}
	}
}

Life::~Life()
{
	for (int count = 0; count < A; count++) {
		delete[]space[count];
	}
}

int Life::checkRules(int x, int y)
{
	// space[x][y] = 0; - dead
	// space[x][y] = 1; - alive
	//Moore neighborhood
	int lifeCount = 0;
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			lifeCount += space[i][j];
		}
	}
	lifeCount -= space[x][y];

	//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	//...

	//Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	//Any live cell with more than three live neighbours dies, as if by overpopulation.
	//...

	return space[x][y];
}

void Life::printSpace()
{
	for (int i = 1; i < A - 1; i++) {
		for (int j = 1; j < B - 1; j++) {
			if (space[i][j] == 1)
				cout << "@";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void Life::generateLife()
{
	//we exclude the contour 
	for (int i = 1; i < A - 1; i++) {
		for (int j = 1; j < B - 1; j++) {
			space[i][j] = rand() % 2; // 0 or 1
		}
	}
}

void Life::runLife()
{
	generateLife();
	printSpace();
	Sleep(1000);
	//In an infinite loop 1) we check the condition checkRules from 0 to Size-1; 2) printSpace(); 3) sleep; 4) clear the screen 
	//...
}
