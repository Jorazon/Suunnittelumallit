#pragma once

#include <cstdlib>

class Random {
public:
  static int Generate() {
    return std::rand() | (std::rand() << 16);
  }
};
