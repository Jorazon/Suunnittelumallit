#pragma warning(disable : 6031)

#include <iostream>

#include "Component.h"
#include "Case.h"
#include "Cooler.h"
#include "CPU.h"
#include "GPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "Storage.h"

int main() {

  Component* box = new Case("NZXT H511 Flow Compact", 99.99);
  Component* cooler = new Cooler("Noctua NH-D15", 114.99);
  Component* cpu = new CPU("AMD Ryzen 7 5800X3D", 449.99);
  Component* gpu = new GPU("Asus GeForce TUF-RTX3080-O10G-V2-GAMING", 869.99);
  Component* board = new Motherboard("Asus PRIME B450-PLUS AM4", 114.99);
  Component* ram = new RAM("Kingston FURY Renegade 32GB", 159.99);
  Component* ssd = new Storage("Samsung 980 PRO SSD 1TB", 139.99);

  board->AddComponent(cpu);
  board->AddComponent(ram);
  board->AddComponent(cooler);
  box->AddComponent(board);
  board->AddComponent(gpu);
  box->AddComponent(ssd);

  std::cout << "Total price: " << box->GetTotalPrice();

  getchar();
}
