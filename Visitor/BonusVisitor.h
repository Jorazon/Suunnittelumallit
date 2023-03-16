#pragma once

#include "Player.h"

// Abstract visitor class
class BonusVisitor {
public:
  virtual void visitIdle(Player& player) = 0;
  virtual void visitWalking(Player& player) = 0;
  virtual void visitJumping(Player& player) = 0;
};
