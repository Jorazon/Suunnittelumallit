#pragma warning(disable : 6031)

#include <iostream>
#include <vector>

#include "BonusCalculator.h"
#include "IdlePlayer.h"
#include "WalkingPlayer.h"
#include "JumpingPlayer.h"

int main() {
  BonusCalculator calculator;

  std::vector<Player*> players = { new IdlePlayer(), new WalkingPlayer(), new JumpingPlayer() };

  for (Player* player : players) {
    player->accept(calculator);
  }

  getchar();
}
