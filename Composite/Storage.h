#pragma once

#include "SimpleComponent.h"

class Storage : public SimpleComponent {
public:
  Storage(std::string name, double price) : SimpleComponent(name, price) {};
};
