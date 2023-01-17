#pragma once

#include <ostream>

#include "Shirt.h"

class BossShirt : public Shirt {
private:
  const char* name() {
    return "Boss shirt";
  }
};
