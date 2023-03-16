#pragma once

#include "BonusVisitor.h"

// Concrete visitor class that determines bonus points based on the player's state
class BonusCalculator : public BonusVisitor {
public:
  void visitIdle(Player& player) override {
    player.addBonusPoints(5);
  }

  void visitWalking(Player& player) override {
    player.addBonusPoints(10);
  }

  void visitJumping(Player& player) override {
    player.addBonusPoints(15);
  }
};
