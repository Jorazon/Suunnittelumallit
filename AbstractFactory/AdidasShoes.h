#pragma once

#include <ostream>

#include "Shoes.h"

class AdidasShoes : public Shoes {
private:
  const char* name() {
    return "Adidas shoes";
  }
};
