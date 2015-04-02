/*****************************************
 ** File:    GridGame.h
 ** Project: CMSC 202 Project 4
 ** Author:  Kyle Fritz
 ** Date:    4/23/2014
 ** Lecture Section: 7208 (16)
 ** Discussion Section: 7210 (18)
 ** E-mail:  fritzk1@umbc.edu
 **
 ** This is the file header for the base class GridGame
 ***********************************************/


#ifndef GRIDGAME_H
#define GRIDGAME_H

#include "GameType.h"

class GridGame {
 public:
  // Default Constructor
  GridGame();

  // input: Type of game, name of game
  // output: Creates a GridGame with these characteristics
  GridGame(enum GameType type, const char *name);

  // Copy constructor
  GridGame(GridGame& g);

  // Destructor
  ~GridGame();

  // input: none
  // output: returns m_type
  enum GameType GetType() { return m_type; }

  // input: none
  // output: Provides a greeting to the user based on the type of game
  void OutputGreeting() const;

  // input: none
  // output: creates a board based on m_boardSize
  void OutputBoard() const;

  // input: the player for which the symbol will be used with
  // output: this player is now associated with m_playerSymbols[player]
  char GetPlayerSymbol(int player) const;

  // input: the player making the move, the row, the column of the move
  // output: returns a string telling what you did wrong. If not, it returns
  //    NULL
  const char *IsLegalMove(int player, int row, int col) const;

  // input: none
  // output: Prints stats on the game and who won the game. Returns void
  void OutputResults() const;

  // input: none
  // output: returns m_boardSize
  int GetBoardSize() const;

  // input: the player doing the move, the row, the column of the move
  // output: By default, this function calls DoBasicMove. Returns none.
  void DoMove(int player, int row, int col);

  // input: the player making the move, the row, the column of the move
  // output: puts that player's symbol on the board at the inputted row 
  //   and column
  void DoBasicMove(int player, int row, int col);

  // input: none
  // output: by default, returns that the game is completed
  bool IsDone() const;
  
  char **m_board;
  const char *m_playerSymbols;
  
 protected:
  int m_boardSize;
  enum GameType m_type;
  const char *m_gameName;
  
};

#endif //GRIDGAME_H
