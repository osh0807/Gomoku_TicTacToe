#include "TicTacToe.h"
#include "ProgramTool.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//TicTacToe() is the constructor of TicTacToe() build TicTacToe gameBoard and puts empty default game pieces in it
TicTacToe::TicTacToe(): GameBase(5, "X") {
}

void TicTacToe::print() {
    cout << *this << endl;
}

//done() checks if there is a winner during the TicTacToe game
bool TicTacToe::done() {
    //check if any of horizontal lines include three consecutive same pieces
    for (size_t i = LLCorner; i <= ULCorner; i = i + 5) {
        if (vPcs[i].display != " " && vPcs[i].display == vPcs[i + 1].display
            && vPcs[i].display == vPcs[i + 2].display) {
            if (vPcs[i].display == "X")
            {
                winner = 'X';
            }
            else
            {
                winner = 'O';
            }
            return true;
        }
    }

    //check if any of vertical lines include three consecutive same pieces
    for (size_t i = LLCorner; i <= LRCorner; i++) {
        if (vPcs[i].display != " " && vPcs[i].display == vPcs[i + 5].display
            && vPcs[i].display == vPcs[i + 10].display) {
            if (vPcs[i].display == "X")
            {
                winner = 'X';
            }
            else
            {
                winner = 'O';
            }
            return true;
        }
    }

    //check if a diagonal line from bottom left corner to top right includes three consecutive same pieces
    if (vPcs[LLCorner].display != " " && vPcs[LLCorner].display == vPcs[LLCorner * 2].display
        && vPcs[LLCorner].display == vPcs[LLCorner * 3].display) {
        if (vPcs[LLCorner].display == "X")
        {
            winner = 'X';
        }
        else
        {
            winner = 'O';
        }
        return true;
    }

    //check if a diagonal line from bottom right corner to top left includes three consecutive same pieces
    if (vPcs[LRCorner].display != " " && vPcs[LRCorner].display == vPcs[LRCorner + 4].display
        && vPcs[LRCorner].display == vPcs[LRCorner + 8].display) {
        if (vPcs[LRCorner].display == "X")
        {
            winner = 'X';
        }
        else
        {
            winner = 'O';
        }
        return true;
    }

    return false;
}

//check if the game is a draw
bool TicTacToe::draw() {
    if (done() || movesRemaining != 0) {
        return false;
    }
    return true;
}

//turn() calls the prompt() function and change the player's turn when the move is valid
int TicTacToe::turn() {
    unsigned int a;
    unsigned int b;
    int promptResult = prompt(a, b);

    //if the result of prompt was a non zero failure enum value, return it. 
    if (promptResult == user_quit_game) {
        return user_quit_game;
    }
    if (promptResult == invalid_piece || promptResult == invalid_value || promptResult == spot_filled) {
        return invalid_value;
    }

    //if the prompt() was successful change the players' turn and let users know
    if (plyrNow == "X") {
        plyrNow = "O";
    }
    else if (plyrNow == "O") {
        plyrNow = "X";
    }
    cout << "It is player " << plyrNow << "'s turn Now" << endl;
    cout << endl;
    return success;
}


//operator<< defined for the class ttt
ostream& operator<<(ostream& ost, const TicTacToe& game) {
    int PcsWidth = game.LongestDpLen + 1;
    ost << setw(PcsWidth);

    for (int i = game.height - 1; i >= 0; i--) {
        cout << i << " ";
        for (int j = 0; j < game.width; j++) {
            int whr = game.width * i + j;
            ost << game.vPcs[whr].display << setw(PcsWidth);
        }
        ost << endl;
    }
    ost << "   ";
    for (int k = 0; k < game.width; k++) {
        ost << k << setw(PcsWidth);
    }
    ost << endl;
    return ost;
}
