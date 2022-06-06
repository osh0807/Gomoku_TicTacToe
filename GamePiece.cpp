#include "GamePiece.h"
using namespace std;

//gamePiece() is the constructor of struct gamePiece
GamePiece :: GamePiece(string a, int x, int y)
    : display(a), x_loc(x), y_loc(y) {
}