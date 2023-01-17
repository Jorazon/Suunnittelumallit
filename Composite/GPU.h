#pragma once

#include "SimpleComponent.h"

class GPU : public SimpleComponent {
public:
  GPU(std::string name, double price) : SimpleComponent(name, price) {};
};
