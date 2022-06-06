//GameBase.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the enumerators and functions used in the GameBase.

#include "GameBase.h"
#include "TicTacToe.h"
#include "GomokuGame.h"
#include "ProgramTool.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

GameBase::GameBase(int dimension, string player1)
    : width(dimension), height(dimension), movesRemaining(9), movesPlayed(0), LongestDpLen(1), vPcs({}), xPcs({}), oPcs({}), plyrNow(player1), winner(" ") {
    for (int i = 0; i < width * height; ++i)
    {
        GamePiece defaultPiece = GamePiece(" ", 0, 0);
        vPcs.push_back(defaultPiece);
    }
}

//prompt() prompts users to enter a coordinate
int GameBase::prompt(unsigned int& i, unsigned int& k) {
    string prompted;
    cout << "type coordinates in a valid form in a valid location (inner 9 boxes) (ex) '1,1'" << endl;
    cout << "or type 'quit' to end the game." << endl;
    cout << endl;
    getline(cin, prompted);

    //when the user decided to quit the game 
    if (prompted == "quit") {
        cout << "User quitted game." << endl;
        return user_quit_game;
    }

    //when the user put a badly formed coordinate
    if (prompted.length() != 3 || prompted[1] != ',' || prompted[0] == ' ' || prompted[2] == ' ' || !isdigit(prompted[0]) || !isdigit(prompted[2])) {
        cout << "You entered wrong form of game piece." << endl;
        cout << endl;
        return invalid_piece;
    }
    prompted.replace(1, 1, " ");
    istringstream iss(prompted);
    if (iss >> i >> k) {

        //when the user put a coordinate out of bound
        if (i < CornerLL || i > CornerHL || k < CornerLL || k > CornerHL) {
            cout << "You entered invalid coordinates." << endl;
            cout << endl;
            return invalid_value;
        }
        int whr = width * k + i;

        //when the user put a coordinate already filled
        if (vPcs[whr].display != " ") {
            cout << "The spot you chose is already filled." << endl;
            cout << endl;
            return spot_filled;
        }

        //when the coordinate that user passed all the validity test cases
        //pushed back into the vector
        vPcs[whr].x_loc = i;
        vPcs[whr].y_loc = k;
        vPcs[whr].display = plyrNow;
        movesRemaining--;
        movesPlayed++;

        //print out the gameBoard and current player's valid moves
        print();
        cout << endl;
        cout << "Player " << plyrNow << " Moves: ";
        if (plyrNow == "X") {
            xPcs.push_back(vPcs[whr]);
            for (size_t i = 0; i < xPcs.size(); i++) {
                cout << xPcs[i].x_loc << "," << xPcs[i].y_loc << "; ";
            }
        }
        if (plyrNow == "O") {
            oPcs.push_back(vPcs[whr]);
            for (size_t i = 0; i < oPcs.size(); i++) {
                cout << oPcs[i].x_loc << "," << oPcs[i].y_loc << "; ";
            }
        }
    }
    cout << endl;
    return success;
}

//play() calls the turn() function and repeats it if needed
int GameBase::play() {
    print();
    cout << "TicTacToe game starts from Player X's turn" << endl;
    int turnResult;

    //check if the game is done or a draw and if not, repeatedly calls the turn() to continue the game
    while (done() == false && draw() == false)
    {
        turnResult = turn();
        if (turnResult == user_quit_game) {
            return user_quit_game;
        }
    }

    //if the game is done let users know the winner and return success code
    if (done() == true) {
        cout << "Player " << winner << " win!" << endl;
        return success;
    }

    //if the game is a draw let users know how many turns are made and return draw_game error code
    if (draw() == true) {
        cout << "game is a Draw" << endl;
        cout << movesPlayed << " turns have been made" << endl;
        cout << "number of winning moves remaining: " << movesRemaining << endl;
        return draw_game;
    }

    return success;
}

GameBase* GameBase::GameType(int argc, char* argv[]) {
    if (argc == num_argument) {
        string FileName = argv[input_file_name];
        if (FileName == "TicTacToe") {
            try {
                TicTacToe* NewGame = new TicTacToe();
                return NewGame;
            }
            catch (std::bad_alloc& ba)
            {
                std::cerr << "bad_alloc caught: " << ba.what() << '\n';
            }  
        }
        if (FileName == "Gomoku") {
            try {
                GomokuGame* NewGame = new GomokuGame();
                return NewGame;
            }
            catch (std::bad_alloc& ba)
            {
                std::cerr << "bad_alloc caught: " << ba.what() << '\n';
            }
        }

    }
    GameBase* NullPtr = 0;
    return NullPtr;
    
}