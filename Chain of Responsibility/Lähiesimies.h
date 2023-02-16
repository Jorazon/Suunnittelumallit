#pragma once

#include "RaiseHandler.h"

class Lähiesimies : public RaiseHandler {
  bool Handle(double increase);
};

bool Lähiesimies::Handle(double increase) {
  if (increase <= 0.02) {
    std::cout << "L\204hiesimies hoiti" << std::endl;
    return true;
  }
  return superior->Handle(increase);
}
