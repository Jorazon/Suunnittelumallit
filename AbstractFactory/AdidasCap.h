#pragma once

#include <ostream>

#include "Cap.h"

class AdidasCap : public Cap {
private:
  const char* name() {
    return "an Adidas cap";
  }
};
