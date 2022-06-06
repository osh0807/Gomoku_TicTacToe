//GameBase.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the enumerators and functions used for the GameBase.

#pragma once
#include "GamePiece.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameBase {
public:
	GameBase(int dimension, string player1);
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int prompt(unsigned int& i, unsigned int& k);
	virtual int turn() = 0;
	virtual int play();
	static GameBase* GameType(int argc, char* argv[]);

protected:
	int width;
	int height;
	int LongestDpLen;
	int movesRemaining;
	int movesPlayed;
	mutable vector<GamePiece> vPcs;
	mutable vector<GamePiece> xPcs;
	mutable vector<GamePiece> oPcs;
	string plyrNow;
	string winner;
};
