/**
 * \file Print.h
 * \author Shivam Taneja
 * \brief API to print result from board with prototypes of functions and state variables
 */
#ifndef A4_PRINT_H_
#define A4_PRINT_H_

#include <iostream>
#include <iomanip>
#include <vector>

#include "GameBoard.h"

using namespace std;
/**
 *  \brief Class representing the instruction to print GameBoard
 *  \details Includes TWO main components grid (aka board) and the temporary board(for function)
 */
class Print
{
private:


/**
 *  \brief creates 2d array of booleans (square matric)
 * 	\details visible to user, used to print different state of board
 */
  vector<vector<bool>> toBePrint;

public:

/**
*  \brief Constructs a new Board
*/
  Print();

/**
*  \brief prints out the state of the game 
*	 \detail "-" for dead cell/no cell and "O" for alive cells
*/
  void printBoard(Board input);
};

#endif
