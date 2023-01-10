#include "Opettaja.h"

Juoma* Opettaja::CreateJuoma() {
  return new Vesi();
}

Ruoka* Opettaja::CreateRuoka() {
  return new Salaatti();
}
