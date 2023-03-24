#pragma once

// Abstract Builder class
class BurgerBuilder {
public:
  virtual void addPatty() = 0;
  virtual void addSalad() = 0;
  virtual void addCheese() = 0;
};
