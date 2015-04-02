/*****************************************
 ** File:    Reversi.h
 ** Project: CMSC 202 Project 4
 ** Author:  Kyle Fritz
 ** Date:    4/23/2014
 ** Lecture Section: 7208 (16)
 ** Discussion Section: 7210 (18)
 ** E-mail:  fritzk1@umbc.edu
 **
 ** This is the file header for the child class of GridGame, Reversi
 ***********************************************/


#ifndef REVERSI_H
#define REVERSI_H
#include "GridGame.h"

const int REVERSI_BOARD_SIZE = 8;

class Reversi: public GridGame {
 public:

  // Default constructor
  Reversi();

  // Constructor with inputted playerSymbols
  Reversi(const char *playerSymbols);

  // Destructor
  ~Reversi();

  // input: none
  // output: returns whether or not the game is done
  bool IsDone() const;

  // input: the player making the move, the row, the column of the move
  // output: the board changes how it should once this function is completed
  void DoMove(int player, int row, int col);

 protected:

  static bool InBounds(int row, int col, int boardSize);

  void FlipTilesInDir(char playerSym, int row, int rowIncr,
		      int col, int colIncr);
};

#endif //REVERSI_H
