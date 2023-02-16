#pragma warning (disable : 6031)

#include <iostream>

#include "RaiseHandler.h"
#include "Lähiesimies.h"
#include "Päällikkö.h"
#include "Toimitusjohtaja.h"

int main() {
  RaiseHandler* lähiesimies = new Lähiesimies();
  RaiseHandler* päällikkö = new Päällikkö();
  RaiseHandler* toimitusjohtaja = new Toimitusjohtaja();

  lähiesimies->SetSuperior(päällikkö);
  päällikkö->SetSuperior(toimitusjohtaja);

  std::cout << "Palkankorotus 1%" << std::endl;
  lähiesimies->Handle(0.01);
  std::cout << "Palkankorotus 3.5%" << std::endl;
  lähiesimies->Handle(0.035);
  std::cout << "Palkankorotus 6%" << std::endl;
  lähiesimies->Handle(0.06);

  getchar();
}
