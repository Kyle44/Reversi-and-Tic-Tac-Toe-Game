/*****************************************
 ** File:    GridGame.cpp
 ** Project: CMSC 202 Project 4
 ** Author:  Kyle Fritz
 ** Date:    4/23/2014
 ** Lecture Section: 7208 (16)
 ** Discussion Section: 7210 (18)
 ** E-mail:  fritzk1@umbc.edu
 **
 ** This file contains the functions used for the base class GridGame
 ***********************************************/


#include <iostream>
#include <cstdlib>
#include <cstring>
#include "GridGame.h"
#include "Reversi.h"
#include "TicTacToe.h"

using namespace std;


GridGame::GridGame() {
    m_type = GAME_UNKNOWN;
    m_gameName = "Unknown";
}

GridGame::GridGame(enum GameType type, const char *gameName) {
    m_type = type;
    m_gameName = gameName;
    m_playerSymbols = "XO";
}

GridGame::GridGame(GridGame& g)
{
  m_boardSize = g.m_boardSize;
  m_board = g.m_board;
  m_playerSymbols = g.m_playerSymbols;

  m_type = g.m_type;
  m_gameName = g.m_gameName;
}

GridGame::~GridGame()
{
  delete m_board;
  m_board = NULL;
  delete m_playerSymbols;
  m_playerSymbols = NULL;
}

void GridGame::OutputGreeting() const {
  cout << "Welcome to " << m_gameName << "!\n";
}

void GridGame::OutputBoard() const {
  for (int r = 0; r < m_boardSize; r++) {
    for (int c = 0; c < m_boardSize; c++) {
      cout << m_board[r][c];
    }
    cout << endl;
  }
}

/* Returns NULL on good move, else returns err string.
 * Note that this check is game-neutral (at least for TTT and Reversi)
 */
char GridGame::GetPlayerSymbol(int player) const {
  if (player >= static_cast<int>(strlen(m_playerSymbols))) {
    cerr << "GetPlayerSymbol: illegal request\n";
    exit(1);
    }
  return m_playerSymbols[player];
}

const char *GridGame::IsLegalMove(int player, int row, int col) const {
    if (row < 0 || row >= m_boardSize || col < 0 || col >= m_boardSize) {
      return "Row or column out of range";
    }
    else if (m_board[row][col] != '-') {
      return "Position already played";
    }
    else {
      return NULL;
    }
  }

int GridGame::GetBoardSize() const {
  return m_boardSize;
}

void GridGame::DoMove(int player, int row, int col)
{
  DoBasicMove(player, row, col);
}

void GridGame::DoBasicMove(int player, int row, int col) {
  const char *errStr;

  // We're paranoid--double-check
  if ((errStr = IsLegalMove(player, row, col)) != NULL) {
    cerr << errStr << "--exiting\n";
    exit(1);
  }
  m_board[row][col] = m_playerSymbols[player];
}

void GridGame::OutputResults() const {

  int count[2];
  char playerSym[2];
  int boardSize = GetBoardSize();
  
  
  count[0] = count[1] = 0;
  playerSym[0] = GetPlayerSymbol(0);
  playerSym[1] = GetPlayerSymbol(1);
  
  // Tabulate results
  for (int r = 0; r < boardSize; r++) {
    for (int c = 0; c < boardSize; c++) {
      for (int s = 0; s < 2; s++) {
	if (m_board[r][c] == playerSym[s]) {
	  ++(count[s]);
	}
      }
    }
  }
  
  // Finally, find highest score
  for (int s = 0; s < 2; s++) {
    cout << "Player " << playerSym[s] << " conrols " << count[s]
	 << " squares.\n";
  }
  if (count[0] > count[1]) {
    cout << "Player " << playerSym[0] << " wins!\n";
  }
  else if (count[1] > count[0]) {
    cout << "Player " << playerSym[1] << " wins!\n";
  }
  else {
    cout << "The game is a tie\n";
  }
}

bool GridGame::IsDone() const
{
  return true;
}
