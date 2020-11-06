#include <iostream>

using namespace std;

const int BOARD_SIZE = 16;
const int BOARD_LENGTH = 4;

void invoke_start_tic_tac_toe_simulation();
//PURPOSE:  Runs the steps of this program (tic-tac-toe simulation, A4 Q1)

void enter_moves(int& x_score, int& o_score, int& num_ties, bool& first_move_X);
// PURPOSE: Prints initial tic-tac-toe board and alternates turns for player X & O by calling either X_turn or O_turn functions
// INPUTS:  entry - allows players to enter an integer corresponding to the spot they want to claim on the board
//          x_score, o_score - counts each player's score through all the rounds played
//          num_ties - counts the number of ties through all the rounds played
//          first_move_X - defines when player X gets the first move, alternates between true & false every game
//OUTPUTS:  Prints tic-tac-toe board after each turn, displaying the spots claimed by each player and the remaining "empty" spots


int X_turn(string arr[], int array_size, int x);
// PURPOSE: Takes user input for which spot on the board they want to claim and places an X there, performs error checking for if the desired spot is non existent 
//          or already taken, and also adjusts for spacing on the board
// INPUTS:  x - the user's entry for the desired spot
//          arr[] - represents the string array for the printed tic-tac-toe board
//          array_size - the size of the 1D array (16 spaces on the board)


int O_turn(string arr[], int array_size, int x);
// PURPOSE: Takes user input for which spot on the board they want to claim and places an O there, performs error checking for if the desired spot is non existent 
//          or already taken, and also adjusts for spacing on the board
// INPUTS:  x - the user's entry for the desired spot
//          arr[] - represents the string array for the printed tic-tac-toe board
//          array_size - the size of the 1D array (16 spaces on the board)
// OUTPUTS: returns index


void check_for_win(int player, string player_mark, int mark_position, bool& player_win, string gameboard[]);
//PURPOSE:  Checks the row, column, and diagonals of the newly added mark to see if there is winning chain of four
//INPUTS:   player - either 1 or 2, representing which player just added a mark
//          player_mark - either X or O, representing the symbol of the current player
//          mark_position - the location of the newly added mark
//          player_win - a reference to a boolean tracking if the current player has won (true if they win)
//          gameboard - a 4x4 2D array that keeps track of the marks made on the board
//OUTPUTS:  n/a, pass-by-reference

void check_for_win(int player, string player_mark, int mark_position, bool& player_win, string gameboard[]) {
    
    //Step 1: Check Row
    int current_row = (mark_position) / BOARD_LENGTH;
    bool found_win = true;

    //runs down the column, checking if they are all equal to the current player's mark. Stops once a non-matching mark is found OR if the player has won from a previous check
    for (int col = 0; col < 4 && !player_win && found_win; col++) {
        //if all the previous ones matched AND the current column also matches, keep true, else, set to false
        found_win = found_win && (gameboard[current_row * BOARD_LENGTH + col] == player_mark);
    }

    player_win = found_win;

    //Step 2: Check the column
    int current_col = (mark_position) % BOARD_LENGTH;
    found_win = true;

    for (int row = 0; row < 4 && !player_win && found_win; row++) {
        //if all the previous ones matched AND the current row also matches, keep true, else, set to false
        found_win = found_win && (gameboard[row * BOARD_LENGTH + current_col] == player_mark);
    }
    player_win = found_win;

    //Step 3: Checks the diagonals (top left to bottom right)
    //checks if the mark was made in the TL to BR diagonal
    if (current_row == current_col) {
        found_win = true;

        for (int i = 0; i < 4 && !player_win && found_win; i++) {
            found_win = found_win && (gameboard[i * BOARD_LENGTH + i] == player_mark);
        }

        player_win = found_win;
    }
    
    //Step 4: Checks the diagonals (bottom left to top right)
    //checks if the mark was made in the BL to TR diagonal
    if ((current_row + current_col) == 3) {
        found_win = true;

        for (int i = 0; i < 4 && !player_win && found_win; i++) {
            found_win = found_win && (gameboard[i * 4 + (BOARD_LENGTH - 1 - i)] == player_mark);
        }

        player_win = found_win;
    }
}


void invoke_start_tic_tac_toe_simulation() {
    //[SETUP] Declare and initialize variables
    int x_score = 0, o_score = 0, num_ties = 0;


    bool keep_playing = true;
    string continue_check;

    bool first_move_X = true; //represents which player it going first this round, X first is true, O first is false

    while (keep_playing) {
        //[INPUT/OUTPUT] Output game board, Get next move, Store it
        enter_moves(x_score, o_score, num_ties, first_move_X);

        //[INPUT] Do you still want to play?

        cout << "Do you still want to play? Enter 'Y' to continue or 'N' to end: ";
        cin >> continue_check;

        while (continue_check != "Y" && continue_check != "N") {
            cout << "Invalid input. Do you still want to play? Enter 'Y' to continue or 'N' to end: ";
            cin >> continue_check;
        }

        if (continue_check == "Y") {
            keep_playing = true;
        } 
        else if (continue_check == "N") {
            keep_playing = false;
        }

        first_move_X = !first_move_X;
    }
    //[OUTPUT]
    cout << "Game Over!" << endl;
    cout << "Player 1 earned " << x_score << " point(s)." << endl;
    cout << "Player 2 earned " << o_score << " point(s)." << endl;
    cout << "There were " << num_ties << " ties." << endl;
}

int main()
{
    int player = 1;
    string mark = "X";
    int position = 1;
    bool has_won = false;
    string X = "X";
    string O = "O";
    string board[16] = {X, O, X, X, 
                      X, X, X, X, 
                      O, X ,X, O, 
                      X, O, O, X };


    invoke_start_tic_tac_toe_simulation();
}
//-----------------------------------------

//allows for X player's turn, take in an input (checks that its valid # and not filled), and adds to the array----
int X_turn(string arr[], int array_size, int x) { // whenever it's X's turn, changes the number on board to X

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
    return index;

}


int O_turn(string arr[], int array_size, int x) { // whenever it's O's turn, changes the number on board to O

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
    return index;
}

//this outputs the current board, and calls function for either X or O to input a value
void enter_moves(int& x_score, int& o_score, int& num_ties, bool& first_move_X) {

    int entry = 0;
    int array_size = 16;
    int index = 0;
    bool is_X_turn = first_move_X;
    bool is_O_turn = !first_move_X;

    bool X_win = false;
    bool O_win = false;
    int player = 1;


    string board[16] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };

    cout << "Welcome to Tic Tac Toe! For the first round, X will start. Afterwards, the starting player will alternate between X and O." << endl;

    for (int i = array_size; i > 0 && !X_win && !O_win; i--) { // keeps asking for user input until all spots are filled OR until a player wins

        cout << board[0] << "      " << board[1] << "      " << board[2] << "      " << board[3] << endl; // printing the board every turn 
        cout << board[4] << "      " << board[5] << "      " << board[6] << "      " << board[7] << endl;
        cout << board[8] << "      " << board[9] << "     " << board[10] << "     " << board[11] << endl;
        cout << board[12] << "     " << board[13] << "     " << board[14] << "     " << board[15] << endl;
        cout << " " << endl;

        cout << "Please enter the number corresponding to the location you would like to claim." << endl;

        if (is_X_turn) { // X's turn to play
            index = X_turn(board, array_size, entry);
            is_X_turn = false;
            is_O_turn = true;
            check_for_win(player, "X", index, X_win, board);
        }

        else if (is_O_turn) { // O's turn to play
            index = O_turn(board, array_size, entry);
            is_O_turn = false;
            is_X_turn = true;
            check_for_win(player, "O", index, O_win, board);
        }
    }

    if (X_win) {
        cout << "*** ROUND OVER. Player X wins! ***" << endl;
        x_score++;

    }

    if (O_win) {
        cout << "*** ROUND OVER. Player O wins! ***" << endl;
        o_score++;
    }

    if (!X_win && !O_win) {
        cout << "*** ROUND OVER. It was a tie! ***" << endl;
        num_ties++;
    }

}


