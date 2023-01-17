#pragma once

#include <ostream>

class Shoes {
private:
  virtual const char* name() { return "shoes"; };
public:
  friend std::ostream& operator<<(std::ostream& os, Shoes* shoes);
};

std::ostream& operator<<(std::ostream& os, Shoes* shoes) {
  return os << shoes->name();
}
