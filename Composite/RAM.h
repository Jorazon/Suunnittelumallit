#pragma once

#include "SimpleComponent.h"

class RAM : public SimpleComponent {
public:
  RAM(std::string name, double price) : SimpleComponent(name, price) {};
};
