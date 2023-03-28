#pragma once

#include "AterioivaOtus.h"
#include "Vesi.h"
#include "Salaatti.h"

class Opettaja : public AterioivaOtus
{
public:
  Juoma* CreateJuoma();
  Ruoka* CreateRuoka();
};

Juoma* Opettaja::CreateJuoma() {
  return new Vesi();
}

Ruoka* Opettaja::CreateRuoka() {
  return new Salaatti();
}
