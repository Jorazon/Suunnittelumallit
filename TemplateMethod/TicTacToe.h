#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "Game.h"

class TicTacToe : public Game {
private:
  int board[3][3] = {0};
  int turnPlayer = -1;
  const char* markers = " XO";
  bool tieEnd;
  void printBoard();
  void printSelect();
  int* XYformI(int i, int w, int h);
public:
  void initializeGame();
  void makePlay(int player);
  bool endOfGame();
  void printWinner();
};

/**
 * @brief Print board
*/
void TicTacToe::printBoard() {
  std::string boardString = "";
  for (int x = 0; x < 3 * 2 + 1; x++) {
    for (int y = 0; y < 3 * 2 + 1; y++) {
      if (x % 2 == 0 && y % 2 == 0) {
        // corner
        if (x == 0 && y == 0)              boardString += (char)201;
        else if (x == 3 * 2 && y == 0)     boardString += (char)200;
        else if (x == 0 && y == 3 * 2)     boardString += (char)187;
        else if (x == 3 * 2 && y == 3 * 2) boardString += (char)188;
        // edge
        else if (x == 0)                   boardString += (char)203;
        else if (x == 3 * 2)               boardString += (char)202;
        else if (y == 0)                   boardString += (char)204;
        else if (y == 3 * 2)               boardString += (char)185;
        // interior
        else                               boardString += (char)206;
      }
      // horizontal
      else if (x % 2 == 0) boardString += (char)205;
      // vertical
      else if (y % 2 == 0) boardString += (char)186;
      // playable spots
      else boardString += markers[board[(x / 2)][y / 2]];
    }
    boardString.append("\n");
  }
  printf("%s", boardString.c_str());
}

/**
 * @brief Print spot selection
*/
void TicTacToe::printSelect() {
  std::string selection = "";
  selection += markers[turnPlayer + 1];
  selection.append("s turn.\n");
  selection.append("Select space.\n");
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (board[x][y] == 0) {
        selection.append(std::to_string(1 + (y + 3 * x)));
      }
      else {
        selection.append("-");
      }
      selection.append(" ");
    }
    selection.append("\n");
  }
  printf("%s", selection.c_str());
}

/**
 * @brief Calculate position from index
 * @param i index
 * @param w board width
 * @param h board height
 * @return x,y position
*/
int* TicTacToe::XYformI(int i, int w, int h) {
  return new int[2] {i % w, i / h};
}

void TicTacToe::initializeGame() {
  if (playersCount != 2) throw std::invalid_argument("Game only supports two players.");
  // empty board
  for (auto& x : board) {
    for (auto& y : x) {
      y = 0;
    }
  }
}

void TicTacToe::makePlay(int player) {
  turnPlayer = player;
  printBoard();
  printSelect();
  // get player's move location
  int* coords;
  while (true) {// try to get input
    printf("Selection: ");
    int selected;
    std::cin >> selected;
    // test input range is valid
    if (selected >= 1 && selected <= 9) {
      coords = XYformI(selected - 1, 3, 3);
      // test input location is available
      if (board[coords[1]][coords[0]] == 0) break;
    }
    printf("Invalid selection");
    printf("\033[F\033[K");// move cursor to start of previous line
  }
  printf("\033[0;0H\033[2J");// clear screen
  // set location
  board[coords[1]][coords[0]] = turnPlayer + 1;
}

bool TicTacToe::endOfGame() {
  bool hasWinner = false;
  bool tie = true;
  //check for vertical win
  for (int x = 0; x < 3; x++) {
    hasWinner |= ((board[0][x] != 0) && (board[0][x] == board[1][x]) && (board[0][x] == board[2][x]));
  }
  //check for horizontal win
  for (int y = 0; y < 3; y++) {
    hasWinner |= ((board[y][0] != 0) && (board[y][0] == board[y][1]) && (board[y][0] == board[y][2]));
  }
  //check for diagonal win
  hasWinner |= ((board[0][0] != 0) && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]));
  hasWinner |= ((board[0][2] != 0) && (board[0][2] == board[1][1]) && (board[0][2] == board[2][0]));
  //chack for a tie (all spaces full and no winner)
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      tie &= board[y][x] != 0;
    }
  }
  tieEnd = tie;

  return hasWinner || tie;
}

void TicTacToe::printWinner() {
  printBoard();
  if (!tieEnd) printf("%c wins!", markers[turnPlayer + 1]);
  else printf("Tie!");
}
