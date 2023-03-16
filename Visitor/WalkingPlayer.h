#pragma once

#include "Player.h"

// Concrete context class representing a walking player
class WalkingPlayer : public Player {
public:
  void accept(BonusVisitor& visitor) override;
};

void WalkingPlayer::accept(BonusVisitor& visitor) {
  visitor.visitWalking(*this);
}
