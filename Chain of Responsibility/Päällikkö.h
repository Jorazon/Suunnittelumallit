#pragma once

#include "RaiseHandler.h"

class Päällikkö : public RaiseHandler {
  bool Handle(double increase);
};

bool Päällikkö::Handle(double increase) {
  if (increase > 0.02 && increase < 0.05) {
    std::cout << "P\204\204llikk\224 hoiti" << std::endl;
    return true;
  }
  return superior->Handle(increase);
}
