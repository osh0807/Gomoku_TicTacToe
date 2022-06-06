#pragma once
#include "GameBase.h"
#include "ProgramTool.h"

using namespace std;

class GomokuGame : public GameBase {
public:
	GomokuGame();
	void print();
	virtual bool done();
	virtual bool draw();
	virtual int prompt(unsigned int& i, unsigned int& k);
	virtual int turn();
	friend ostream& operator<< (ostream& ost, const GomokuGame& game);

protected:

};

//overiding operator<< for the class TicTacToe
ostream& operator<< (ostream& ost, const GomokuGame& game);