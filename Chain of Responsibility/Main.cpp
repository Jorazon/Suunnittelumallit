#pragma warning (disable : 6031)

#include <iostream>

#include "RaiseHandler.h"
#include "L�hiesimies.h"
#include "P��llikk�.h"
#include "Toimitusjohtaja.h"

int main() {
  RaiseHandler* l�hiesimies = new L�hiesimies();
  RaiseHandler* p��llikk� = new P��llikk�();
  RaiseHandler* toimitusjohtaja = new Toimitusjohtaja();

  l�hiesimies->SetSuperior(p��llikk�);
  p��llikk�->SetSuperior(toimitusjohtaja);

  std::cout << "Palkankorotus 1%" << std::endl;
  l�hiesimies->Handle(0.01);
  std::cout << "Palkankorotus 3.5%" << std::endl;
  l�hiesimies->Handle(0.035);
  std::cout << "Palkankorotus 6%" << std::endl;
  l�hiesimies->Handle(0.06);

  getchar();
}
