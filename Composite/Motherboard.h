#pragma once

#include "CompositeComponent.h"

class Motherboard : public CompositeComponent {
public:
  Motherboard(std::string name, double price) : CompositeComponent(name, price) {};
};
