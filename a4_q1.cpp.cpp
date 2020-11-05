/*
*/

#include <iostream>
#include <string>
using namespace std;

void X_turn(string arr[], int array_size, int x) { // whenever it's X's turn, changes the number on board to X

    int index = 0;
    cout << "Player X's move:" << endl;
    cin >> x;

    while (x < 1 || x > 16) {
        cout << "Invalid input! Please enter a number from 1-16." << endl;
        cin >> x;
    } // error checking: if the number they enter doesn't exist on the board

    index = x - 1; // eg. if they type in spot 1, the index is 0

    while (arr[index] == "X" || arr[index] == "O") {
        cout << "Oops, that spot is taken! Enter a different location." << endl;
        cin >> x;
        index = x - 1;
    } // error checking: if the spot they choose is already taken

    if (index >= 9 && index <= 15) { // adjusts the spacing for double digit #s
        arr[index] = "X ";
    }

    else {
        arr[index] = "X";
    }
}


void O_turn(string arr[], int array_size, int x) { // whenever it's O's turn, changes the number on board to O

    int index = 0;
    cout << "Player O's move:" << endl;
    cin >> x;

    while (x < 1 || x > 16) {
        cout << "Invalid input! Please enter a number from 1-16." << endl;
        cin >> x;
    } // error checking: if the number they enter doesn't exist on the board

    index = x - 1; // eg. if they type in spot 1, the index is 0

    while (arr[index] == "X" || arr[index] == "O") {
        cout << "Oops, that spot is taken! Enter a different location." << endl;
        cin >> x;
        index = x - 1;
    } // error checking: if the spot they choose is already taken

    if (index >= 9 && index <= 15) { // adjust spacing for double digit #s
        arr[index] = "O ";
    }

    else {
        arr[index] = "O";
    }
}


void enter_moves() {

    int entry = 0;
    int array_size = 16;
    int index = 0;
    bool is_X_turn = true;
    bool is_O_turn = false;
    string board[16] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };

    cout << "Welcome to Tic Tac Toe! For the first round, X will start. Afterwards, the starting player will alternate between X and O." << endl;

    for (int i = array_size; i > 0; i--) { // keeps asking for user input until all spots are filled 
        
        cout << board[0] << "      " << board[1] << "      " << board[2] << "      " << board[3] << endl; // printing the board every turn 
        cout << board[4] << "      " << board[5] << "      " << board[6] << "      " << board[7] << endl;
        cout << board[8] << "      " << board[9] << "     " << board[10] << "     " << board[11] << endl;
        cout << board[12] << "     " << board[13] << "     " << board[14] << "     " << board[15] << endl;
        cout << " " << endl;
        
        cout << "Please enter the number corresponding to the location you would like to claim." << endl;

        if (is_X_turn) { // X's turn to play
            X_turn(board, array_size, entry);
            is_X_turn = false;
            is_O_turn = true;
        }

        else if (is_O_turn) { // O's turn to play
            O_turn(board, array_size, entry);
            is_O_turn = false;
            is_X_turn = true;
        }
    }
}


int main()
{
    enter_moves();
}

