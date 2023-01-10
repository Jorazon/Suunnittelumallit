#include "Opiskelija.h"

Juoma* Opiskelija::CreateJuoma() {
  return new Kahvi();
}

Ruoka* Opiskelija::CreateRuoka() {
  return new Nuudelit();
}