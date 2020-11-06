#include <iostream>

using namespace std;

const int BOARD_SIZE = 16;
const int BOARD_LENGTH = 4;

void invoke_start_tic_tac_toe_simulation();
//PURPOSE:  Runs the steps of this program (tic-tac-toe simulation, A4 Q1)

void check_for_win(int player, char player_mark, int mark_position, bool& player_win, char gameboard[]);
//PURPOSE:  Checks the row, column, and diagonals of the newly added mark to see if there is winning chain of four
//INPUTS:   player - either 1 or 2, representing which player just added a mark
//          player_mark - either X or O, representing the symbol of the current player
//          mark_position - the location of the newly added mark
//          player_win - a reference to a boolean tracking if the current player has won (true if they win)
//          gameboard - a 4x4 2D array that keeps track of the marks made on the board
//OUTPUTS:  n/a, pass-by-reference

void check_for_win(int player, char player_mark, int mark_position, bool& player_win, char gameboard[]) {
    //Step 1: Check Row
    int current_row = (mark_position - 1) / BOARD_LENGTH;
    bool found_win = true;

    //runs down the column, checking if they are all equal to the current player's mark. Stops once a non-matching mark is found OR if the player has won from a previous check
    for (int col = 0; col < 4 && !player_win && found_win; col++) {
        //if all the previous ones matched AND the current column also matches, keep true, else, set to false
        found_win = found_win && (gameboard[current_row * BOARD_LENGTH + col] == player_mark);
    }

    player_win = found_win;

    //Step 2: Check the column
    int current_col = (mark_position - 1) % BOARD_LENGTH;
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

void get_next_move(int player, char p1_mark, int current_position);
void output_board(char gameboard[]);

void invoke_start_tic_tac_toe_simulation() {
    //[SETUP] Declare and initialize variables
    int p1_score = 0, p2_score = 0, num_ties = 0;
    char p1_mark = 'X', p2_mark = 'O';
    bool p1_wins = false, p2_wins = false;

    bool keep_playing = true;
    char gameboard[16] = { 0 };

    int current_position = 0;
    int current_player = 0;
    char current_player_mark = 'X';

    while (keep_playing) {
        //[INPUT] Get next move, Store it
        get_next_move(current_player, p1_mark, current_position);

        //[OUTPUT] Update game board
        output_board(gameboard);

        //[PROCESSING] Check for chain of four
        check_for_win(current_player, current_player_mark, current_position, p1_wins, gameboard);

        //  > Update score and end game if win, reset
        //  > switch player, reloop

        //[INPUT] Do you still want to play?
        cout << "Do you still want to play? Enter 1 to continue or 0 to end: ";
        cin >> keep_playing;
    }
    //[OUTPUT]
    cout << "Game Over!" << endl;
    cout << "Player 1 earned " << p1_score << " points." << endl;
    cout << "Player 2 earned " << p2_score << " points." << endl;
    cout << "There were " << num_ties << " ties." << endl;
}


int main()
{
    int player = 1;
    char mark = 'X';
    int position = 1;
    bool has_won = false;
    char X = 'X';
    char O = 'O';
    char board[16] = { X, O, X, X,
                      X, X, X, X,
                      O, X ,X, O,
                      X, O, O, X };

    cout << position << " - " << mark << endl;
    int row_count = 0;
    for (int i = 0; i < 16; i++) {

        cout << board[i] << " ";
        row_count++;
        if (row_count == 4) {
            cout << endl;
            row_count = 0;
        }

    }


    check_for_win(player, mark, position, has_won, board);



    cout << (has_won ? "yes" : "no");
}

