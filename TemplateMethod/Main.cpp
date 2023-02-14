#pragma warning(disable : 6031)

#include <iostream>

#include "TicTacToe.h"

int main() {
  Game *game = new TicTacToe();

  game->playOneGame(2);

  getchar();
}
