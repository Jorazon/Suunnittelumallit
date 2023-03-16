#pragma once

#include "Player.h"

// Concrete context class representing a jumping player
class JumpingPlayer : public Player {
public:
  void accept(BonusVisitor& visitor) override;
};

void JumpingPlayer::accept(BonusVisitor& visitor) {
  visitor.visitJumping(*this);
}
