/*****************************************
 ** File:    TicTacToe.h
 ** Project: CMSC 202 Project 4
 ** Author:  Kyle Fritz
 ** Date:    4/23/2014
 ** Lecture Section: 7208 (16)
 ** Discussion Section: 7210 (18)
 ** E-mail:  fritzk1@umbc.edu
 **
 ** This is the file header for the child class of GridGame, TicTacToe
 ***********************************************/


#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridGame.h"

const int TICTACTOE_BOARD_SIZE = 3;

class TicTacToe: public GridGame {
 public:

  // Default constructor
  TicTacToe();

  // TicTacToe board with user inputted symbols
  TicTacToe(const char *playerSymbols);

  // Destructor
  ~TicTacToe();

  // input: the player making the move, the row, the column of the move
  // output: Calls DoBasicMove from GridGame. Returns void.
  void DoMove(int player, int row, int col);

  // input: none
  // output: returns whether or not the game has ended
  bool IsDone();

  // input: none
  // output: Prints out who won the game. Returns void.
  void OutputResults() const;
  
 private:
  // The winner of the game
  char m_winner;
  
  // Boolean used for OutputResults()
  bool m_bool;
};

#endif //TICTACTOE_H
