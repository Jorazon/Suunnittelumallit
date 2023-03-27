#pragma warning(disable : 6031)

#include <iostream>

#include "HesburgerBuilder.h"
#include "McDonaldsBuilder.h"

int main(void) {
  HesburgerBuilder LayerBurger;
  McDonaldsBuilder BigMac;

  LayerBurger.addSalad();
  LayerBurger.addCheese();
  LayerBurger.addPatty();
  LayerBurger.addPatty();
  LayerBurger.addCheese();
  LayerBurger.addSalad();

  BigMac.addPatty();
  BigMac.addSalad();
  BigMac.addPatty();
  BigMac.addCheese();
  BigMac.addSalad();

  std::cout << "Big Mac has:\n" << BigMac << "\n";

  std::cout << "Layer Burger has:\n" << LayerBurger << "\n";

  getchar();
}
