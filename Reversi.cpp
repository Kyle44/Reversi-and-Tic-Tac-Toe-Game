/*****************************************
 ** File:    Reversi.cpp
 ** Project: CMSC 202 Project 4
 ** Author:  Kyle Fritz
 ** Date:    4/23/2014
 ** Lecture Section: 7208 (16)
 ** Discussion Section: 7210 (18)
 ** E-mail:  fritzk1@umbc.edu
 **
 ** This file contains the methods for Reversi objects
 ***********************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Reversi.h"

using namespace std;


Reversi::Reversi()
  : GridGame(GAME_REVERSI, "Reversi") {
  m_playerSymbols = "XO";

  m_boardSize = REVERSI_BOARD_SIZE;
  m_board = new char *[m_boardSize];
  for (int r = 0; r < m_boardSize; r++) {
    m_board[r] = new char[m_boardSize];
    for (int c = 0; c < m_boardSize; c++) {
      m_board[r][c] = '-';
    }
  }
}

Reversi::Reversi(const char *playerSymbols)
  : GridGame(GAME_REVERSI, "Reversi") {
  m_playerSymbols = playerSymbols;
  m_boardSize = REVERSI_BOARD_SIZE;
  m_board = new char *[m_boardSize];
  for (int r = 0; r < m_boardSize; r++) {
    m_board[r] = new char[m_boardSize];
    for (int c = 0; c < m_boardSize; c++) {
      m_board[r][c] = '-';
    }
  }
}

Reversi::~Reversi()
{
  delete m_board;
  m_board = NULL;
  delete m_playerSymbols;
  m_playerSymbols = NULL;
}

/*
 * Puts new piece for player at {row, col} position
 * Preconditions:
 *   Assumes position has already been pre-checked by IsLegalMove() for
 *   valid bounds and emptiness.
 */
void Reversi::DoMove(int player, int row, int col) {
  int rowIncr, colIncr;
  char playerSym = GetPlayerSymbol(player);

  DoBasicMove(player, row, col);
  for (rowIncr = -1; rowIncr <= 1; rowIncr++) {
    for (colIncr = -1; colIncr <= 1; colIncr++) {
      if (rowIncr || colIncr) { // Going in some direction
	FlipTilesInDir(playerSym, row, rowIncr, col, colIncr);
      }
    }
  }
}

bool Reversi::InBounds(int row, int col, int boardSize) {
  return (row >= 0 && row < boardSize && col >= 0 && col < boardSize);
}

void Reversi::FlipTilesInDir(char playerSym, int row, int rowIncr, int col, int colIncr) {
  int r, c;
  int boardSize = GetBoardSize();

  for (r = row + rowIncr, c = col + colIncr; InBounds(r, c, boardSize);
       r += rowIncr, c += colIncr) {
    if (m_board[r][c] == '-') {
      break;
    }
    else if (m_board[r][c] == playerSym) {
      // We found a range of pieces to flip--Work backwards flipping
      // Note: in following, need to test both r and c, since one or
      // other might not be changing
      for (r -= rowIncr, c -= colIncr; r != row || c!= col;
	   r -= rowIncr, c -= colIncr) {
	m_board[r][c] = playerSym;
      }
      return;
    }
  }
}

bool Reversi::IsDone() const {
  int boardSize = GetBoardSize();

  for (int r = 0; r < boardSize; r++) {
    for (int c = 0; c < boardSize; c++) {
      if (m_board[r][c] == '-') {
	return false;
      }
    }
  }
  return true;
}
