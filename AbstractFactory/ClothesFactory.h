#pragma once

#include "Cap.h"
#include "Shirt.h"
#include "Jeans.h"
#include "Shoes.h"

class ClothesFactory {
public:
  virtual Cap*   CreateCap()   = 0;
  virtual Shirt* CreateShirt() = 0;
  virtual Jeans* CreateJeans() = 0;
  virtual Shoes* CreateShoes() = 0;
};
