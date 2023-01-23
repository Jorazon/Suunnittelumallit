#pragma warning(disable : 6031)

#include <iostream>
#include <fstream>

#include "Casper.h"
#include "AdidasFactory.h"
#include "BossFactory.h"

int main() {

  Casper* casper = nullptr;

  std::ifstream file("FactoryName.txt");
  std::string line;
  file >> line;

  if (line == "AdidasFactory") {
    casper = new Casper(new AdidasFactory());
  }
  else if (line == "BossFactory") {
    casper = new Casper(new BossFactory());
  }

  if (casper) {
    std::cout << casper;
  }

  getchar();
}
