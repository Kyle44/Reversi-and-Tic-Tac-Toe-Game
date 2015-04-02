/*****************************************
 ** File:    TicTacToe.cpp
 ** Project: CMSC 202 Project 4
 ** Author:  Kyle Fritz
 ** Date:    4/23/2014
 ** Lecture Section: 7208 (16)
 ** Discussion Section: 7210 (18)
 ** E-mail:  fritzk1@umbc.edu
 **
 ** This file contains the methods for TicTacToe objects
 ***********************************************/


#include <iostream>
#include <cstring>
#include <cstdlib>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() 
  :GridGame(GAME_TICTACTOE, "TicTacToe")
{
  m_boardSize = TICTACTOE_BOARD_SIZE;
  m_playerSymbols = "XO";
  m_bool = false;
  m_board = new char *[m_boardSize];
  for (int r = 0; r < m_boardSize; r++) {
    m_board[r] = new char[m_boardSize];
    for (int c = 0; c < m_boardSize; c++) {
      m_board[r][c] = '-';
    }
  }
}

TicTacToe::TicTacToe(const char *playerSymbols)
  :GridGame(GAME_TICTACTOE, "TicTacToe")
{
  m_boardSize = TICTACTOE_BOARD_SIZE;
  m_playerSymbols = playerSymbols;
  m_bool = false;
  m_board = new char *[m_boardSize];
  for (int r = 0; r < m_boardSize; r++) {
    m_board[r] = new char[m_boardSize];
    for (int c = 0; c < m_boardSize; c++) {
      m_board[r][c] = '-';
    }
  }
}

TicTacToe::~TicTacToe()
{
  delete m_board;
  m_board = NULL;
  delete m_playerSymbols;
  m_playerSymbols = NULL;
}

void TicTacToe::DoMove(int player, int row, int col) {
  DoBasicMove(player, row, col);
}

void TicTacToe::OutputResults() const
{
  if (m_bool == true)
    cout << "Player " << m_winner << " wins!" << endl;
  else
    cout << "The game is a tie" << endl;
}

bool TicTacToe::IsDone() {
  // for loops for possible Tic Tac Toe combinations
  if (m_board[0][0] == m_board[0][1])
    if (m_board[0][1] == m_board[0][2])
      if (m_board[0][0] != '-'){
	m_bool = true;
	m_winner = m_board[0][0];
	return true;
      }
  if (m_board[1][0] == m_board[1][1])
    if(m_board[1][1] == m_board[1][2])
      if (m_board[1][0] != '-'){
	m_bool = true;
	m_winner = m_board[1][0];
	return true;
      }
  if (m_board[2][0] == m_board[2][1]) 
    if (m_board[2][1] == m_board[2][2])
      if (m_board[2][0] != '-'){
	m_bool = true;
	m_winner = m_board[2][0];
	return true;
      }
  if (m_board[0][0] == m_board[1][0]) 
    if (m_board[1][0] == m_board[2][0])
      if (m_board[0][0] != '-'){
	m_bool = true;
	m_winner = m_board[0][0];
	return true;
      }
  if (m_board[0][1] == m_board[1][1])
    if (m_board[1][1] == m_board[2][1]) 
      if (m_board[0][1] != '-'){
	m_bool = true;
	m_winner = m_board[0][1];
	return true;
      }
  if (m_board[0][2] == m_board[1][2]) 
    if(m_board[1][2] == m_board[2][2])
      if (m_board[0][2] != '-'){
	m_bool = true;
	m_winner = m_board[0][2];
	return true;
      }
  if (m_board[0][0] == m_board[1][1]) 
    if (m_board[1][1] == m_board[2][2])
      if (m_board[0][0] != '-'){
	m_bool = true;
	m_winner = m_board[0][0];
	return true;
      }
  if (m_board[2][0] == m_board[1][1]) 
    if (m_board[1][1] == m_board[0][2])
      if (m_board[2][0] != '-'){
	m_bool = true;
	m_winner = m_board[2][0];
	return true;
      }
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
