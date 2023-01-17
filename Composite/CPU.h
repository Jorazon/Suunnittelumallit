#pragma once

#include "SimpleComponent.h"

class CPU : public SimpleComponent {
public:
  CPU(std::string name, double price) : SimpleComponent(name, price) {};
};
