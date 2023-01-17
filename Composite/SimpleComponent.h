#pragma once

#include <stdexcept>

#include "Component.h"

class SimpleComponent : public Component {
private:
  std::string name;
  double price;
public:
  SimpleComponent(std::string name, double price);
  std::string GetName();
  double GetPrice();
  double GetTotalPrice();
  void AddComponent(Component* component);
};

SimpleComponent::SimpleComponent(std::string name, double price) {
  this->name = name;
  this->price = price;
}

std::string SimpleComponent::GetName(){
  return name;
}

double SimpleComponent::GetPrice(){
  return price;
}

double SimpleComponent::GetTotalPrice(){
  return GetPrice();
}

void SimpleComponent::AddComponent(Component* component){
  throw std::runtime_error("Cannot add subcomponents to simple component.");
}
