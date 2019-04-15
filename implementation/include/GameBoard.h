/**
 * \file GameBoard.h
 * \author Shivam Taneja
 * \brief API for board with prototypes of functions and state variables
 */
#ifndef A4_GAMEBOARD_H_
#define A4_GAMEBOARD_H_

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
/**
 *  \brief Class representing the GameBoard
 *  \details Includes TWO main components grid (aka board) and the temporary board(for function)
 */
class Board{
	private:

/**
 *  \brief creates 2d array of booleans (square matric)
 * 	\details visible to user and main operations occurs in this matrix
 */
		bool board[25][25] ;


/**
 *  \brief creates 2d array of booleans (square matric)
 * 	\details Not visible to user, used to check last state of primary matrix
 */
		bool temp[25][25];

/**
 *  \brief creates 2d array of booleans (square matric)
 * 	\details Not visible to user, used to check make changes to board indirectly
 */
		bool board2[25][25];

/**
*  \brief changes the state of the given cell in the board
*  \param al number of alive cells beside the cell
*  \param x X-coordinate of the cell 
*  \param y Y-coordinate of the cell 
*/
		void neighbourStateChange(int al, int x, int y);

/**
*  \brief makes a copy of the board (2d list) to work on without disturnbing the primary board
*  \param 2d list of boolean
 */

		void compare();

	  public:
/**
*  \brief Constructs a new Board
*/
		Board();

/**
*  \brief creates a board in accordance to the input file (alive cells coordinates)
*  \param filename Path of the file - must be txt
*/
		void createBoard(string filename);

/**
*  \brief saves the state of the game
*	 \detail save the state in the state of game in log.txt -	it saves the cooradinates of alive cells
*/
		void saveGame();

/**
*  \brief deletes saved game
*	 \detail deletes saved log.txt file
*/
		void removeSaved();

		/**
*  \brief changes the state of the board (2d list)
*	 \detail 1. Any live cell with fewer than two live neighbours dies (referred to as underpopulation or exposure[1]).
*					 2. Any live cell with more than three live neighbours dies (referred to as overpopulation or overcrowding).
*	         3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
* 				 4. Any dead cell with exactly three live neighbours will come to life
*/
		void state();

/**
*  \brief Check the last state and the current state 
*  \return true -> both previous and current state is same, else -> false
*/
		bool prevState();

	/**
*  \brief this copy is for the temporary 2d list
*/
		void copy();





		vector<vector<bool>> printState();
};

#endif
