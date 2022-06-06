// Lab4.cpp
// by Soohoon Oh; soohoonoh@wustl.edu
// : This file contains the 'main' function. Program execution begins and ends there.
// It also includes definitions of functions declared in LAb3.h
//
#include "ProgramTool.h"
#include "TicTacToe.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//main() function executes the program

int main(int argc, char* argv[])
{
    GameBase* GameTypePtr = GameBase::GameType(argc, argv);
    if (GameTypePtr == 0) {
        return user_message(argv[program_name], "Wrong number of arguments!");
    }
    shared_ptr<GameBase> SharedGamePtr(GameTypePtr);
    return GameTypePtr -> play();

}

//user_message() returns error code and let the user know what errot they got
int user_message(string pgName, string errInfo) {
    cout << "usage: [" << pgName << " TicTacToe]" << endl;
    cout << errInfo << endl;
    return wrong_arg;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
