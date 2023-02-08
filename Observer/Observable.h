#pragma once

#include <unordered_set>

#include "Observer.h"

class Observer;

class Observable {
public:
  void Attach(Observer *observer) {
    observers.insert(observer);
  }
  void Detach(Observer *observer) {
    observers.erase(observer);
  }
private:
  std::unordered_set<Observer*> observers;
protected:
  void Notify() {
    for (Observer *observer : observers) {
      observer->Update(this);
    }
  }
};
