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

void AterioivaOtus::Syö() {
  if (!ruoka) {
    ruoka = CreateRuoka();
  }
  std::cout << "Kyll\204p\204 " << ruoka << " maistuukin hyv\204lt\204\n";
}

void AterioivaOtus::Juo() {
  if (!juoma) {
    juoma = CreateJuoma();
  }
  std::cout << "Aterian j\204lkeen " << juoma << " tekee ter\204\204\n";
}
