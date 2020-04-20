/* FUNCTION DECLARATIONS */

/* FUNCTION TO LOAD A SUDOKU BOARD DATA FILE INTO A 2D CHARACTER ARRAY */
// INPUT
// filename: filename of board to be loaded passed in as character array
// board: 9 by 9 character array which stores the Sudoku board
// OUTPUT
// void
void load_board(const char* filename, char board[9][9]);

/* FUNCTION TO DISPLAY A SUDOKU BOARD TO THE STANDARD OUTPUT */
// INPUT
// board: 9 by 9 character array which stores the Sudoku board
// OUTPUT
// void
void display_board(const char board[9][9]);

/* FUNCTION TO CHECK IF A SUDOKU BOARD IS COMPLETE */
// INPUT
// board: 9 by 9 character array which stores the Sudoku board
// OUTPUT
// bool: boolean which is set to true when board is complete; false otherwise
bool is_complete(const char board[9][9]);

/* FUNCTION WHICH MAKES A MOVE ON SUDOKU BOARD IF VALID */
// INPUT
// board: 9 by 9 character array which stores the Sudoku board
// position: character array which has the position on which move is to be made
// digit: character that is the value to be placed on the position
// OUTPUT
// bool: boolean which is set to true when move is valid & made; false otherwise
bool make_move(const char position[2], char digit, char board[9][9]);

/* FUNCTION TO SAVE SUDOKU BOARD TO AN OUTPUT FILE */
// INPUT
// filename: character array which contains name of destination file
// board: 9 by 9 character array which stores the Sudoku board
// OUTPUT
// bool: boolean which is set to true when save was successful; false otherwise
bool save_board(const char filename[], char board[9][9]);

/* FUNCTION TO SOLVE SUDOKU BOARD */
// INPUT
// board: 9 by 9 character array which stores the Sudoku board
// OUTPUT
// bool: boolean which is set to true if board is solved; false otherwise
bool solve_board(char board[9][9]);

/* END OF FUNCTION DECLARATIONS */
