#pragma once

#include <iostream>

class Juoma
{
private:
  virtual const char* GetNimi() { return "juoma"; }
public:
  friend std::ostream& operator<<(std::ostream& os, Juoma* juoma) {
    return os << juoma->GetNimi();
  }
};
