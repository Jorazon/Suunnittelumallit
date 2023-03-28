#pragma once

#include "AterioivaOtus.h"
#include "Energiajuoma.h"
#include "Pitsa.h"

class Koodari : public AterioivaOtus
{
public:
  Juoma* CreateJuoma();
  Ruoka* CreateRuoka();
};

Juoma* Koodari::CreateJuoma() {
  return new Energiajuoma();
}

Ruoka* Koodari::CreateRuoka() {
  return new Pitsa();
}
