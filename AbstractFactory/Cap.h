#pragma once

#include <ostream>

class Cap {
private:
  virtual const char* name() { return "a cap"; };
public:
  friend std::ostream& operator<<(std::ostream& os, Cap* cap);
};

std::ostream& operator<<(std::ostream& os, Cap* cap) {
  return os << cap->name();
}
