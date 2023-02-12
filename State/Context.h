#pragma once

#include "State.h"

class State;

class Context {
protected:
  State* state = nullptr;
public:
  Context();
  Context(State *initialState);
  void changeState(State *state);
};

Context::Context() {
  this->state = nullptr;
}

Context::Context(State *initialState) {
  this->state = initialState;
}

void Context::changeState(State *state) {
  this->state = state;
  this->state->SetContext(this);
}
