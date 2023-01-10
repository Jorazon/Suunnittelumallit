#pragma warning(disable : 6031)

#include "AterioivaOtus.h"
#include "Opettaja.h"
#include "Opiskelija.h"
#include "Koodari.h"

int main() {
  AterioivaOtus* opettaja = new Opettaja();
  opettaja->Aterioi();

  AterioivaOtus* opiskeija = new Opiskelija();
  opiskeija->Aterioi();

  AterioivaOtus* koodari = new Koodari();
  koodari->Aterioi();

  getchar();
}
