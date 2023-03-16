#pragma once

#include "BonusVisitor.h"

class BonusVisitor;

// Abstract context class representing a player
class Player {
public:
  virtual void accept(BonusVisitor& visitor) = 0;
  void addBonusPoints(int points);

protected:
  int points_ = 0;
};

void Player::addBonusPoints(int points) {
  points_ += points;
  printf("Player %p now has %d points.\n", (void*)this, points_);
}
