#pragma once

#include <string>

#include "Jump.h"

class Jumper {
private:
  int completed_jumps_ = 0;
  std::string name_;
  Jump* jumps_[2]{};
public:
  Jumper(std::string name) : name_(name) {}

  Jump* jump() {
    if (completed_jumps_ >= 2) return nullptr;

    jumps_[completed_jumps_] = new Jump();
    return jumps_[completed_jumps_++];
  }

  Jump** getJumps() {
    return jumps_;
  }

  std::string getName() {
    return name_;
  }
};
