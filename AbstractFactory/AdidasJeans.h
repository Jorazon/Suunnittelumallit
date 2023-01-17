#pragma once

#include <ostream>

#include "Jeans.h"

class AdidasJeans : public Jeans {
private:
  const char* name() {
    return "Adidas jeans";
  }
};
