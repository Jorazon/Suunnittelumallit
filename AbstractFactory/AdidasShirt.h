#pragma once

#include <ostream>

#include "Shirt.h"

class AdidasShirt : public Shirt {
private:
  const char* name() {
    return "Adidas shirt";
  }
};