#pragma once

class Life
{
	int spaceX;
	int spaceY;
	int A;
	int B;
	int **space;
	int** inicSpace(int x, int y);
	int checkRules(int x, int y);
	void printSpace();
	void generateLife();
public:
	Life(int X, int Y);
	~Life();
	void runLife();
};

