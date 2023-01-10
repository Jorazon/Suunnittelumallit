#pragma once

#include <iostream>

class Ruoka
{
private:
  virtual const char* GetNimi() { return "juoma"; }
public:
  friend std::ostream& operator<<(std::ostream& os, Ruoka* ruoka) {
    return os << ruoka->GetNimi();
  }
};
