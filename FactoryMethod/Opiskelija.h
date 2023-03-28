#pragma once

#include "AterioivaOtus.h"
#include "Kahvi.h"
#include "Nuudelit.h"

class Opiskelija : public AterioivaOtus
{
public:
  Juoma* CreateJuoma();
  Ruoka* CreateRuoka();
};

Juoma* Opiskelija::CreateJuoma() {
  return new Kahvi();
}

Ruoka* Opiskelija::CreateRuoka() {
  return new Nuudelit();
}
