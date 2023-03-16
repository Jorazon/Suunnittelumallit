#pragma once

#include "Player.h"

// Concrete context class representing an idle player
class IdlePlayer : public Player {
public:
  void accept(BonusVisitor& visitor) override;
};

void IdlePlayer::accept(BonusVisitor& visitor) {
  visitor.visitIdle(*this);
}
