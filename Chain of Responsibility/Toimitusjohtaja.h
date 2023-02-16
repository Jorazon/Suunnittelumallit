#pragma once

#include "RaiseHandler.h"

class Toimitusjohtaja : public RaiseHandler {
  bool Handle(double increase);
};

bool Toimitusjohtaja::Handle(double increase) {
  std::cout << "Toimitusjohtaja hoiti" << std::endl;
  return true;
}
