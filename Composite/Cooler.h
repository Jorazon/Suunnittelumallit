#pragma once

#include "SimpleComponent.h"

class Cooler : public SimpleComponent {
public:
  Cooler(std::string name, double price) : SimpleComponent(name, price) {};
};
