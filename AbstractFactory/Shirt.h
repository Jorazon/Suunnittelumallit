#pragma once

#include <ostream>

class Shirt {
private:
  virtual const char* name() { return "shirt"; };
public:
  friend std::ostream& operator<<(std::ostream& os, Shirt* shirt);
};

std::ostream& operator<<(std::ostream& os, Shirt* shirt) {
  return os << shirt->name();
}
