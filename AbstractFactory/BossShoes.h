#pragma once

#include <ostream>

#include "Shoes.h"

class BossShoes : public Shoes {
private:
  const char* name() {
    return "Boss shoes";
  }
};
