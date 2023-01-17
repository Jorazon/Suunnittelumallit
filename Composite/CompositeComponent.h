#pragma once

#include <vector>

#include "Component.h"

class CompositeComponent : public Component {
private:
  std::vector<Component*> subcomponents;
  std::string name;
  double price;
public:
  CompositeComponent(std::string name, double price);
  std::string GetName();
  double GetPrice();
  double GetTotalPrice();
  void AddComponent(Component* component);
};

CompositeComponent::CompositeComponent(std::string name, double price) {
  this->name = name;
  this->price = price;
}

std::string CompositeComponent::GetName() {
  return name;
}

double CompositeComponent::GetPrice() {
  return price;
}

double CompositeComponent::GetTotalPrice() {
  double sum = 0.0;
  for (Component* component : subcomponents) {
    sum += component->GetTotalPrice();
  }
  return price + sum;
}

void CompositeComponent::AddComponent(Component* component) {
  subcomponents.push_back(component);
}
