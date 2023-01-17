#pragma warning(disable : 6031)

#include <iostream>

#include "Casper.h"
#include "AdidasFactory.h"
#include "BossFactory.h"

int main() {

  Casper* casper = new Casper(new AdidasFactory());
  std::cout << casper;
  
  casper = new Casper(new BossFactory());
  std::cout << casper;

  getchar();
}
