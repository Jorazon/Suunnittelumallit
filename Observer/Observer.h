#pragma once

#include "Observable.h"

class Observable;

class Observer {
public:
  virtual void Update(Observable* observable) {
    printf("Don't update abstract observer!!!");
  };
};
