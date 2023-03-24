#pragma once

#include "Random.h"

class Judge {
public:
  // Judge the style of the jump and give a score of up to 20
  float judge() {
    return  20.0f * Random::getInstance().rand();
  }
};
