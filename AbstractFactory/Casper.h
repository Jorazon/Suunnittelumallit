#pragma once

#include <ostream>

#include "ClothesFactory.h"

class Casper {
private:
  ClothesFactory* factory;
public:
  Casper(ClothesFactory* factory) {
    this->factory = factory;
  }
  friend std::ostream& operator<<(std::ostream& os, const Casper* casper);
};

std::ostream& operator<<(std::ostream& os, const Casper* casper) {
  return os << "I'm Casper the C++ coder, and im wearing " <<
    casper->factory->CreateCap() << ", " <<
    casper->factory->CreateShirt() << ", " <<
    casper->factory->CreateJeans() << " and " <<
    casper->factory->CreateShoes() << ".\n";
}
