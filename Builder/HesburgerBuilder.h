#pragma once

#include <vector>
#include <string>

#include "BurgerBuilder.h"

// Concrete Builders
class HesburgerBuilder : public BurgerBuilder {
public:
  void addPatty() override {
    parts.push_back(new BeefPatty());
  }

  void addSalad() override {
    parts.push_back(new IcebergSalad());
  }

  void addCheese() override {
    parts.push_back(new CheddarCheese());
  }
  
  class Ingredient {
  public:
    virtual std::string getDescription() const = 0;
  };

  std::vector<HesburgerBuilder::Ingredient*> getBurger() {
    return parts;
  }

  friend std::ostream& operator<<(std::ostream& os, HesburgerBuilder& burger) {
    for (auto ingredient : burger.getBurger()) {
      os << ingredient->getDescription().c_str() << ", ";
    }
    return os;
  }

private:
  std::vector<Ingredient*> parts;

  class BeefPatty : public Ingredient{
    std::string getDescription() const override {
      return "Beef Patty";
    }
  };

  class IcebergSalad : public Ingredient {
    std::string getDescription() const override {
      return "Iceberg Salad";
    }
  };

  class CheddarCheese : public Ingredient {
    std::string getDescription() const override {
      return "Cheddar Cheese";
    }
  };
};
