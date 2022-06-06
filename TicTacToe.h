#pragma once
#include "GamePiece.h"
#include "GameBase.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//objects representing components of the TicTacToe game
class TicTacToe : public GameBase {
public:
	TicTacToe();
	friend ostream& operator<<(ostream& ost, const TicTacToe& game);
	void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn();

protected:

};

//overiding operator<< for the class TicTacToe
ostream& operator<< (ostream& ost, const TicTacToe& game);

