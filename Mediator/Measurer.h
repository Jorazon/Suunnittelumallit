#pragma once

#include "Random.h"

class Measurer {
public:
  // Measure the length of the jump
  float measure() {
    return 150.0f * Random::Random::getInstance().rand() + 100.0f;
  }
};
