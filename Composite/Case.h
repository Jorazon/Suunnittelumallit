#pragma once

#include "CompositeComponent.h"

class Case : public CompositeComponent {
public:
  Case(std::string name, double price) : CompositeComponent(name, price) {};
};
