#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* GLOBAL CONSTANT DECLARATIONS */
// Define the maximum number of columns & rows and the digit bounds
int const max_number_of_rows = 9;
int const max_number_of_columns = 9;
int const max_value = 9;
int const min_value = 1;

/* GLOBAL VARIABLE DECLARATIONS */
// Define  counter to check the number of recursive steps
int counter = 0;

/* HELPER FUNCTION DECLARATIONS */
// Helper functions that have been created are declared here and not
// in the header file since we would not like external users to
// access these
void print_frame(int row);
void print_row(const char* data, int row);
bool recursive_solver(int row, int column, int value, char board[9][9]);
bool valid_move(int row, int column, int value, char board[9][9]);

/* FUNCTION DEFINITIONS */
/* PRE-SUPPLIED FUNCTION TO LOAD A SUDOKU BOARD FROM A FILE */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << '\n';
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9); //check that while loop has succesfully executed
}
/* END OF FUNCTION */


/* INTERNAL HELPER FUNCTION */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << '\n';
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
}
/* END OF FUNCTION */


/* INTERNAL HELPER FUNCTION */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << '\n';
}
/* END OF FUNCTION */


/* PRE-SUPPLIED FUNCTION TO DISPLAY A SUDOKU BOARD */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}
/* END OF FUNCTION */


/* FUNCTION THAT CHECKS IF BOARD IS COMPLETE */
bool is_complete(const char board[9][9]) {

  // A board is considered complete when all spaces are filled with integers from 1 to 9
  for (int j=0; j<max_number_of_columns; j++)
    {
      for (int i=0;i<max_number_of_columns;i++)
	{

	  if(static_cast<int>(board[i][j]-'0') < min_value || static_cast<int>(board[i][j]-'0') > max_value)
	    return false;

	}
    }
  
  return true;
}
/* END OF FUNCTION */


/* FUNCTION TO PLACE DIGIT IF MOVE IS VALID */
bool make_move(const char position[2], char digit, char board[9][9]) {

  // Convert the position and digit to integers to simplify subsequent logical operations
  // Rows and columns map onto integers from 0 to 8 where 0 matches A for rows and 1 for columns

  int value = static_cast<int>(digit - '0');
  int row = static_cast<int>(position[0] - 'A');
  int column = static_cast<int>(position[1] - '1');
  
  // Use the helper function valid_move to check if the move is logically correct
  // Assign digit if correct and return true
  if(valid_move(row, column, value, board))
  {
    board[row][column] = digit;
    return true;
  }
  else {
    return false;
  }
}
/* END OF FUNCTION */


/* FUNCTION TO SAVE BOARD TO OUTPUT FILE */
bool save_board(const char filename[], char board[9][9]) {

  // Output message to user to indicate saving is in progress
  cout << "Saving Sudoku board to file ' " << filename << " '... ";

  // Open output stream and check if successful 
  ofstream out(filename);  
  if(!out)
     cout << "Failed!" << '\n';
  assert(out);

  // Loop over all rows and columns; Output every value and use a new line for every row  
  int row = 0;
  
  while(row < max_number_of_rows) 
  { 
      for (int column = 0; column < max_number_of_columns; column++)
	{
	  out.put(board[row][column]);
	}
      out.put('\n');
      row++;
  }

  // Check whether all values have been looped over by checking the row counter declared earlier
  // Print out success to the user if it is correct and return true; Otherwise abort programme
  cout << ((row == max_number_of_rows) ? "Success!" : "Failed!") << '\n';
  assert(row == max_number_of_rows);
  return true;
}
/* END OF FUNCTION */


/* FUNCTION TO SOLVE SUDOKU BOARD */
bool solve_board(char board[9][9])
{
  counter = 0;
  
  // Run the recursive solver helper function starting at the top left with the min_value
  if (recursive_solver(0, 0, min_value, board)) 
    {
      cout << "Number of iterations to solve: " << counter << '\n' << '\n';
      return true;
    }
  else
    {
      return false;
    }
}
/* END OF FUNCTION */


/* HELPER FUNCTION TO CHECK WHETHER A MOVE IS VALID */
bool valid_move(int row, int column, int value, char board[9][9]) {

  
  // Check if digit is correct
  if (!(value >= min_value && value <= max_value))
    return false;

  // Check coordinates are valid
  if (!(row >= 0 && row <= 8 && column >= 0 && column <= 8))
    return false;

  // Check if value is empty
  if (board[row][column] != '.')
    return false;

  // Check whether the digit is already placed in the current row & column
  for (int i = 0; i < max_number_of_rows; i++)
    {
      if (static_cast<int>(board[row][i]-'0') == value || static_cast<int>(board[i][column]-'0') == value)
	return false;
    }

  // Check whether the value is already in the same 'box'
  // Find box which it is in; Boxes are numbered from left to right starting from the top
  int box_row  = row/3;
  int column_row = column/3;
  
  // Check if box contains value by looping through all values of the box
  for (int i = box_row*3; i < 3*box_row+3; i++)
    {
      for (int j = column_row*3; j < 3*column_row+3; j++)
	{
	  if (static_cast<int>(board[i][j]-'0') == value)
	    return false;
	}
    }

  return true;
}
/* END OF FUNCTION */


/* HELPER FUNCTION WHICH RECURSIVELY SOLVES THE SUDOKU */
bool recursive_solver(int row, int column, int value, char board[9][9]) {

  // Check if the board is complete
  if (is_complete(board))
    {
      return true;
    }
  
   counter++;
  
  // Check if the solver went over the board; Go to next column if so
  // (Remember that row index goes from 0 to 8) 
  if (row == max_number_of_rows)
    {
      return recursive_solver(0, column+1, min_value, board);
    }

  // Check if the position is empty; Skip to next position if so
  if (board[row][column] != '.')
    {
      return recursive_solver(row+1, column, min_value, board);
    }

  // Loop through possible values for the current position
  // If the move is valid, place it on the board 

  // The if statement checks if the function returns true for the next position
  // This creates a string of function calls to itself (i.e. recursion) until
  // either the board is filled with correct moves or a call returns false since
  // there was no valid move available; The placed value is then set to empty again
  // and the loop continues with an incremented value (i.e. when there are no
  // valid options for the current position, the value at previous position is
  // incremented)

  // When the first call to this function (i.e. the one from solve_board)
  // has finished the loop without a valid solution, all possible options
  // have been checked and false is returned to solve_board
  
  for (; value <= max_value; value++)
    {
      if (valid_move(row, column, value, board))
	{
	  board[row][column] = static_cast<char>(value + '0');
	  if (recursive_solver(row+1, column, min_value, board))
	    return true;
	  board[row][column] = '.';
	    
	}
    }

  return false;
}
/* END OF FUNCTION */
/* END OF FUNCTION DEFINITIONS */
