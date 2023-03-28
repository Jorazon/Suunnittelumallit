#pragma once

#include "Sorter.h"

class Context {
private:
  Sorter* strategy = __nullptr;
public:
  void SetStrategy(Sorter* strategy);
  void sort(std::vector<int>& array);
};

void Context::SetStrategy(Sorter* strategy) {
  this->strategy = strategy;
}

void Context::sort(std::vector<int>& array) {
  if (strategy == nullptr) return;
  strategy->sort(array);
}
