#pragma once

#include "ClothesFactory.h"
#include "AdidasCap.h"
#include "AdidasShirt.h"
#include "AdidasJeans.h"
#include "AdidasShoes.h"

class AdidasFactory : public ClothesFactory {
public:
  Cap*   CreateCap();
  Shirt* CreateShirt();
  Jeans* CreateJeans();
  Shoes* CreateShoes();
};

Cap* AdidasFactory::CreateCap() {
  return new AdidasCap();
}

Shirt* AdidasFactory::CreateShirt() {
  return new AdidasShirt();
}

Jeans* AdidasFactory::CreateJeans() {
  return new AdidasJeans();
}

Shoes* AdidasFactory::CreateShoes() {
  return new AdidasShoes();
}
