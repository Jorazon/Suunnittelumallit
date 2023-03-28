#pragma once

#include "Sorter.h"

class Insert : public Sorter {
public:
  void sort(std::vector<int>& array);
};

void Insert::sort(std::vector<int>& array) {
  int temp;
  for (size_t i = 1; i < array.size(); i++) {
    for (size_t j = i; j > 0; j--) {
      if (array[j] < array[j - 1]) {
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      }
    }
  }
}
