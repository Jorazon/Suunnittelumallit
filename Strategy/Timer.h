#pragma once

#include <chrono>

class Timer {
private:
  typedef std::chrono::high_resolution_clock clock;
  typedef std::chrono::duration<double, std::ratio<1>> second;
  std::chrono::time_point<clock> start;
public:
  Timer() : start(clock::now()) {}
  void reset() { start = clock::now(); }
  long long elapsed() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
      clock::now() - start
      ).count();
  }
};