#pragma once

#include <string>

class Component {
public:
  virtual std::string GetName() = 0;
  virtual double GetPrice() = 0;
  virtual double GetTotalPrice() = 0;
  virtual void AddComponent(Component* component) = 0;
};
