#pragma once
#include <string>
using namespace std;

struct GamePiece {
	GamePiece(string a, int x, int y);
	string display;
	int x_loc;
	int y_loc;
};
