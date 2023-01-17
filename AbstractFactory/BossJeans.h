#pragma once

#include <ostream>

#include "Jeans.h"

class BossJeans : public Jeans {
private:
  const char* name() {
    return "Boss jeans";
  }
};
