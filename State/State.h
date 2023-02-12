#pragma once

#include "Context.h"

class Context;

class State {
protected:
  Context *context;
public:
  State();
  State(Context *initialContext);
  void SetContext(Context *context);
};

State::State() {
  context = nullptr;
}

State::State(Context *initialContext) {
  this->context = initialContext;
}

void State::SetContext(Context *context) {
  this->context = context;
}
