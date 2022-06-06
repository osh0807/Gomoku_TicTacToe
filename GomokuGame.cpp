#include "GomokuGame.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

GomokuGame::GomokuGame() : GameBase(19, "B") {
}

void GomokuGame::print() {
    cout << *this << endl;
}

bool GomokuGame::done() {
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            int NowIndex = width * (i - 1)  + j - 1;
            int ComparedIndex = NowIndex + 1;
            int CheckDone = 1;
            if (vPcs[NowIndex].display != " ") {
                //horizontal
                while (ComparedIndex < width * height) {
                    if (vPcs[ComparedIndex].y_loc == vPcs[NowIndex].y_loc && vPcs[ComparedIndex].display == vPcs[NowIndex].display) {
                        CheckDone++;
                    }
                    else {
                        CheckDone = 1;
                    }
                    if (CheckDone == 5) {
                        winner = vPcs[NowIndex].display;
                        return true;
                    }
                    ComparedIndex++;
                }

                //vertical
                ComparedIndex = NowIndex + 19;
                CheckDone = 1;
                while (ComparedIndex < width * height) {
                    if (vPcs[ComparedIndex].y_loc <= height && vPcs[ComparedIndex].display == vPcs[NowIndex].display) {
                        CheckDone++;
                    }
                    else {
                        CheckDone = 1;
                    }
                    if (CheckDone == 5) {
                        winner = vPcs[NowIndex].display;
                        return true;
                    }
                    ComparedIndex = ComparedIndex + 19;
                }

                //Right Diagonal
                ComparedIndex = NowIndex + 20;
                CheckDone = 1;
                while (ComparedIndex < width * height) {
                    if (vPcs[ComparedIndex].x_loc > vPcs[NowIndex].x_loc && vPcs[ComparedIndex].display == vPcs[NowIndex].display) {
                        CheckDone++;
                    }
                    else {
                        CheckDone = 1;
                    }
                    if (CheckDone == 5) {
                        winner = vPcs[NowIndex].display;
                        return true;
                    }
                    ComparedIndex = ComparedIndex + 20;
                }

                //Left Diagonal
                ComparedIndex = NowIndex + 18;
                CheckDone = 1;
                while (ComparedIndex < width * height){
                    if (vPcs[ComparedIndex].x_loc < vPcs[NowIndex].x_loc && vPcs[ComparedIndex].display == vPcs[NowIndex].display) {
                        CheckDone++;
                    }
                    else {
                        CheckDone = 1;
                    }
                    if (CheckDone == 5) {
                        winner = vPcs[NowIndex].display;
                        return true;
                    }
                    ComparedIndex = ComparedIndex + 18;
                }
            }
        }
    }
    return false;
}

bool GomokuGame::draw() {
    if (!done()) {
        GomokuGame CopyforB = *this;
        GomokuGame CopyforW = *this;
        for (int i = 1; i <= CopyforB.height; i++) {
           
            for (int j = 1; j <= CopyforB.width; j++) {
                int whr = width * (i - 1) + j - 1;
                if (CopyforB.vPcs[whr].display == " ") {
                    GamePiece BPiece = GamePiece("B", j-1, i-1);
                    CopyforB.vPcs[whr] = BPiece;
                }
            }
        }
        for (int i = 1; i<= CopyforW.height; i++) {
            for (int j = 1; j<= CopyforW.width; j++) {
                int whr = width * (i - 1) + j - 1;
                if (CopyforW.vPcs[whr].display == " ") {
                    GamePiece WPiece = GamePiece("W", j, i);
                    CopyforW.vPcs[whr] = WPiece;
                }
            }
        }
        if (!CopyforB.done() && !CopyforW.done()) {
            return true;
        }
        return false;
    }
    return false;
}

//prompt() prompts users to enter a coordinate
int GomokuGame::prompt(unsigned int& i, unsigned int& k) {
    string prompted;
    cout << "type coordinates in a valid form in a valid location (19 by 19 grid) (ex) '1,1'" << endl;
    cout << "or type 'quit' to end the game." << endl;
    cout << endl;
    getline(cin, prompted);

    //when the user decided to quit the game 
    if (prompted == "quit") {
        cout << "User quitted game." << endl;
        return user_quit_game;
    }

    //when the user put a badly formed coordinate
    if (prompted.length() < 3 || prompted.length() > 5) {
        cout << "You entered wrong form of game piece 1." << endl;
        cout << endl;
        return invalid_piece;
    }
    else if (prompted.length() == 3) {
        if (prompted[1] != ',' || prompted[0] == ' ' || prompted[2] == ' ' || !isdigit(prompted[0]) || !isdigit(prompted[2])) {
            cout << "You entered wrong form of game piece." << endl;
            cout << endl;
            return invalid_piece;
        }
    }
    else if (prompted.length() == 4) {
        if (prompted[1] == ',') {
            if (!isdigit(prompted[0]) || !isdigit(prompted[2]) || !isdigit(prompted[3])) {
                cout << "You entered wrong form of game piece." << endl;
                cout << endl;
                return invalid_piece;
            }
        }
        else if (prompted[2] == ',') {
            if (!isdigit(prompted[0]) || !isdigit(prompted[1]) || !isdigit(prompted[3])) {
                cout << "You entered wrong form of game piece." << endl;
                cout << endl;
                return invalid_piece;
            }
        }
    }
    else if (prompted.length() == 5) {
        if (!isdigit(prompted[0]) || !isdigit(prompted[1]) || !isdigit(prompted[3]) || !isdigit(prompted[4])) {
            cout << "You entered wrong form of game piece." << endl;
            cout << "gomokucheck" << endl;
            cout << endl;
            return invalid_piece;
        }
    }

    if (prompted[1] == ',') {
        prompted[1] =  ' ';
    }
    else if (prompted[2] == ',') {
        prompted[2] = ' ';
    }

    istringstream iss(prompted);
    if (iss >> i >> k) {

        //when the user put a coordinate out of bound
        if (i < BottomLeft || i > BottomRight || k < BottomLeft || k > BottomRight) {
            cout << "You entered invalid coordinates." << endl;
            cout << endl;
            return invalid_value;
        }
        int whr = width * (k-1) + i-1;

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
        if (plyrNow == "B") {
            xPcs.push_back(vPcs[whr]);
            for (size_t i = 0; i < xPcs.size(); i++) {
                cout << xPcs[i].x_loc << "," << xPcs[i].y_loc << "; ";
            }
        }
        if (plyrNow == "W") {
            oPcs.push_back(vPcs[whr]);
            for (size_t i = 0; i < oPcs.size(); i++) {
                cout << oPcs[i].x_loc << "," << oPcs[i].y_loc << "; ";
            }
        }
    }
    cout << endl;
    return success;
}

int GomokuGame::turn() {
    unsigned int a;
    unsigned int b;
    int promptResult = GomokuGame::prompt(a, b);

    //if the result of prompt was a non zero failure enum value, return it. 
    if (promptResult == user_quit_game) {
        return user_quit_game;
    }
    if (promptResult == invalid_piece || promptResult == invalid_value || promptResult == spot_filled) {
        return invalid_value;
    }

    //if the prompt() was successful change the players' turn and let users know
    if (plyrNow == "B") {
        plyrNow = "W";
    }
    else if (plyrNow == "W") {
        plyrNow = "B";
    }
    cout << "It is player " << plyrNow << "'s turn Now" << endl;
    cout << endl;
    return success;
}

ostream& operator<< (ostream& ost, const GomokuGame& game) {
    int digitLen = game.width / 10;
    int PcsWidth = 0;
    if (game.LongestDpLen > digitLen) {
        PcsWidth = game.LongestDpLen + 1;
    }
    else {
        PcsWidth = digitLen + 1;
    }

    for (int i = game.height; i > 0; i--) {
        cout << setw(PcsWidth) << i << " ";
        for (int j = 1; j <= game.width; j++) {
            int whr = game.width * (i-1) + j-1;
            if (j <= 9) {
                ost << game.vPcs[whr].display << setw(PcsWidth);
            }
            else {
                ost << " " << game.vPcs[whr].display;
            }
            
        }
        ost << endl;
    }
    ost << "  ";
    for (int k = 1; k <= game.width; k++) {
        if (k <= 9) {
            ost << setw(PcsWidth) << k;
        }
        else {
            ost << " " << setw(PcsWidth) << k;
        }
        
    }
    ost << endl;
    return ost;
}

