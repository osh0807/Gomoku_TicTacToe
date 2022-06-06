//ProgramTool.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the enumerators and functions used in the program.
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//enumerations
//enum Args is for checking command line arguments (modified foe Extra credit)
//enum Outcomes is for any error messages or final success message of this program
//enum GameIndices is for intuitive representations of indices used to print out the TicTacToe gameBoard
//enum GomokuIndices is for intuitive representations of indices used to print out the Gomoku gameBoard
enum Args { program_name, input_file_name, num_argument};
enum Outcomes {
	success,
	wrong_arg,
	fail_to_extract,
	invalid_board_size,
	user_quit_game,
	invalid_piece,
	invalid_value,
	spot_filled,
	draw_game
};
enum GameIndices {
	LLCorner = 6,
	LRCorner = 8,
	ULCorner = 16,
	URCorner = 18,
	CornerLL = 1,
	CornerHL = 3,
	CenterLL = 12,
};

enum GomokuIndices {
	BottomLeft = 1,
	BottomRight = 19,
	TopLeft = 343,
	TopRight = 361,
};

//usage message
int user_message(string pgName, string errInfo);