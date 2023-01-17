#pragma once

#include <ostream>

#include "Cap.h"

class BossCap : public Cap {
private:
  const char* name() {
    return "a Boss cap";
  }
};
