#include "Koodari.h"

Juoma* Koodari::CreateJuoma() {
  return new Energiajuoma();
}

Ruoka* Koodari::CreateRuoka() {
  return new Pitsa();
}