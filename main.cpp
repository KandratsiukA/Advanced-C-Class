#include "Life.h"
#include<iostream>

using namespace std;

int main() {
	int x;
	int y;
	cout << "Row = ";
	cin >> x;
	cout << "Column = ";
	cin >> y;
	cout << "\n\n";
	Life game(x, y);
	game.runLife();
	return 0;
}