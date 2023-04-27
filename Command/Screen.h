#pragma once

#include <iostream>

class Screen {
public:
  Screen() {
    isUp = true;
  }

  void GoUp() {
    std::cout
      << "The screen is" 
      << (isUp ? " already " : " ")
      << "up.\n";
    isUp = true;
  }

  void GoDown() {
    std::cout
      << "The screen is" 
      << (isUp ? " " : " already ")
      << "down.\n";
    isUp = false;
  }

private:
  bool isUp;
};
