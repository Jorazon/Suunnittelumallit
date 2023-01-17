#pragma once

#include <ostream>

class Jeans {
private:
  virtual const char* name() { return "jeans"; };
public:
  friend std::ostream& operator<<(std::ostream& os, Jeans* jeans);
};

std::ostream& operator<<(std::ostream& os, Jeans* jeans) {
  return os << jeans->name();
}
