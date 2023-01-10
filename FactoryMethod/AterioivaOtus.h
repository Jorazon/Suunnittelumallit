#pragma once

#include <iostream>

#include "Juoma.h"
#include "Ruoka.h"

class AterioivaOtus
{
private:
  Juoma* juoma = nullptr;
  Ruoka* ruoka = nullptr;
public:
  virtual Juoma* CreateJuoma() = 0;
  virtual Ruoka* CreateRuoka() = 0;
  void Aterioi() { Syö(); Juo(); }
  void Syö();
  void Juo();
};
