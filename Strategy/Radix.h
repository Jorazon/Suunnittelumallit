#pragma once

#include <vector>
#include <cmath>

#include "Sorter.h"

class Radix : public Sorter {
private:
  int getDigit(int number, int n);
  void prefixSum(std::vector<int>& array);
public:
  void sort(std::vector<int>& array);
};

int Radix::getDigit(int number, int n) {
  return ((number / (int)std::pow(10, n - 1)) % 10);
}

void Radix::prefixSum(std::vector<int> &array) {
  for (int i = 1; i < array.size(); i++) {
    array[i] += array[i - 1];
  }
}

void Radix::sort(std::vector<int> &array) {
  int digit = 1;

  while (true) {
    std::vector<int> sorted(array.size());
    std::vector<int> counts(10, 0);
    
    for (int n : array) {
      ++counts[getDigit(n, digit)];
    }

    prefixSum(counts);

    std::vector<int> reverse(array);
    std::reverse(reverse.begin(), reverse.end());

    for (int n : reverse) {
      sorted[--counts[getDigit(n, digit)]] = n;
    }

    if (array == sorted) break;

    array = sorted;

    ++digit;
  }
}
