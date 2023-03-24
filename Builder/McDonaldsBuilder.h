#pragma once

#include <string>

#include "BurgerBuilder.h"

class McDonaldsBuilder : public BurgerBuilder {
public:
  void addPatty() override {
    burger.append("Beef Patty, ");
  }

  void addSalad() override {
    burger.append("Iceberg Salad, ");
  }

  void addCheese() override {
    burger.append("Cheddar Cheese, ");
  }

  std::string getBurger() {
    return burger;
  }

private:
  std::string burger = "";
};
