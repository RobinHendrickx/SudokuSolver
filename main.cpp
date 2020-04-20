#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

/* MAIN FUNCTION */
// The original code is left unaltered; extra code is added where necessary

int main() {

  char board[9][9];


  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============" << "\n\n";

  cout << "Calling load_board():" << '\n';
  load_board("easy.dat", board);

  cout << '\n' << "Displaying Sudoku board with display_board():" << '\n';
  display_board(board);
  cout << "Done!" << "\n\n";



  
  /* QUESTION 1 */
  cout << "=================== Question 1 ===================" << "\n\n";

  
  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << "\n\n";



  
  /* QUESTION 2 */
   cout << "=================== Question 2 ===================" << "\n\n";

   
  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  // STRESS TESTS
  // Test if value on same spot works
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  // Test if same value in box works
  cout << "Putting '2' into A2 is ";
  if (!make_move("A2", '2', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  // Test if same value in row works
  cout << "Putting '5' into B3 is ";
  if (!make_move("A1", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
    
  // Test if same value in column works
  cout << "Putting '7' into A2 is ";
  if (!make_move("A2", '7', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
    
  // Test if 0 works
  cout << "Putting '0' into A9 is ";
  if (!make_move("A9", '0', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  // Test if wrong coordinates work
  cout << "Putting '1' into A0 is ";
  if (!make_move("A0", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);



  
  /* QUESTION 3 */
  cout << "=================== Question 3 ===================" << "\n\n";

  
  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << '\n';
  else
    cout << "Save board failed." << '\n';
  cout << '\n';

  // Check if we can open our newly saved file and display it
  cout << "Calling load_board():" << '\n';
  load_board("easy-copy.dat", board);

  cout << '\n' << "Displaying Sudoku board with display_board():" << '\n';
  display_board(board);
  cout << "Done!" << "\n\n";



  
  /* QUESTION 4 */
  cout << "=================== Question 4 ===================" << "\n\n";

  
  // SOLVING EASY AND MEDIUM BOARDS
  // Solve and display the easy board
  load_board("easy.dat", board);
  display_board(board);

  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution to 'easy' board  cannot be found." << '\n';
  cout << '\n';

  // Solve and display the medium board
  load_board("medium.dat", board);
  display_board(board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution to 'medium' board cannot be found." << '\n';
  cout << '\n';

  // EXTRA TESTS
  // Try to solve empty board
  load_board("empty.dat", board);
  display_board(board);  
  if (solve_board(board)) {
    cout << "The 'empty' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "Solving the 'empty' board did not work." << '\n';
  cout << '\n';



  
  /* QUESTION 5 */
  cout << "=================== Question 5 ===================" << "\n\n";


  //SOLVE THE MYSTERY BOARDS
  // Solve and display the mystery1 board
  load_board("mystery1.dat", board);
  display_board(board);
  if (solve_board(board)) {
    cout << "The 'mystery 1' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution to 'mystery 1' board cannot be found." << '\n';
  cout << '\n';

  // Solve and display the mystery2 board
  load_board("mystery2.dat", board);
  display_board(board);
  if (solve_board(board)) {
    cout << "The 'mystery 2' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution to 'mystery 2' board cannot be found." << '\n';
  cout << '\n';
  
  // Solve and display the mystery3 board
  load_board("mystery3.dat", board);
  display_board(board);
  if (solve_board(board)) {
    cout << "The 'mystery 3' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution to 'mystery 3' board cannot be found." << '\n';
  cout << '\n';

  // EXTRA TESTS
  // Try to solve an already solved board
  if (solve_board(board)) {
    cout << "Solving the 'mystery 3' board twice gave the solution:" << '\n';
    display_board(board);
  } else
    cout << "Solving the 'mystery 3' board twice did not work." << '\n';
  cout << '\n';

  // Try to solve an extra hard board found online
    // Try to solve empty board
  load_board("hardest.dat", board);
  display_board(board);  
  if (solve_board(board)) {
    cout << "The 'hardest' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "Solving the 'hardest' board did not work." << '\n';
  cout << '\n';

  // Try to solve broken board that has same value twice in a box
  
  // This test breaks the programme; This is since logical validity
  // of the board is not checked in the load_board function
  // However, checking the logical
  // validity of the input board is considered out of scope

  /* 
  load_board("broken.dat", board);
  display_board(board);  
  if (solve_board(board)) {
    cout << "The 'broken' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "Solving the 'broken' board did not work." << '\n';
  cout << '\n';
  */

  // Try to solve board with 0 in it

  // This test breaks the programme; This is since the isdigit()
  // used in load_board also accepts the character '0'

  /*
  load_board("zero.dat", board);
  display_board(board);  
  if (solve_board(board)) {
    cout << "The 'zero' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "Solving the 'zero' board did not work." << '\n';
  cout << '\n';
  */


  // Check what happens when you input a board with letters

  // This error is caught by the isdigit() in load_board

  /*
  load_board("wrongchar.dat", board);
  display_board(board);    if (solve_board(board)) {
    cout << "The 'wrongchar' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "Solving the 'wrong' board did not work." << '\n';
  cout << '\n';
  */
	
  return 0;
}
