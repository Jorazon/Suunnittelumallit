#include "AterioivaOtus.h"

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
