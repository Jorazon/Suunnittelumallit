#pragma once

#include "ClothesFactory.h"
#include "BossCap.h"
#include "BossShirt.h"
#include "BossJeans.h"
#include "BossShoes.h"

class BossFactory : public ClothesFactory {
public:
  Cap*   CreateCap();
  Shirt* CreateShirt();
  Jeans* CreateJeans();
  Shoes* CreateShoes();
};

Cap* BossFactory::CreateCap() {
  return new BossCap();
}

Shirt* BossFactory::CreateShirt() {
  return new BossShirt();
}

Jeans* BossFactory::CreateJeans() {
  return new BossJeans();
}

Shoes* BossFactory::CreateShoes() {
  return new BossShoes();
}
