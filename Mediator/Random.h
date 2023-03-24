#pragma once

#include <stdlib.h>
#include <time.h>

class Random {
private:
  Random() { srand(time(NULL)); };
  Random(const Random&) = delete;
  Random& operator=(const Random&) = delete;

public:
  static Random& getInstance() {
    static Random instance;
    return instance;
  }

  // Returns a random float in range [0..1[
  float rand() {
    return ((float)std::rand() / (float)RAND_MAX);
  }
};
