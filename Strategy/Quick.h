#pragma once

#include "Sorter.h"

class Quick : public Sorter {
public:
  void sort(std::vector<int>& array);
private:
  std::vector<int> array;
  size_t length = 0;
  void quickSort(size_t lowerIndex, size_t higherIndex);
  void exchangeNumbers(size_t i, size_t j);
};

void Quick::sort(std::vector<int>& array) {
  if (array.empty()) {
    return;
  }
  this->array = array;
  length = array.size();
  quickSort(0, length - 1);
  array = this->array;
}

void Quick::quickSort(size_t lowerIndex, size_t higherIndex) {

  size_t i = lowerIndex;
  size_t j = higherIndex;
  // calculate pivot number, I am taking pivot as middle index number
  size_t pivot = array[lowerIndex + (higherIndex - lowerIndex) / 2];
  // Divide into two arrays
  while (i <= j) {
    /**
     * In each iteration, we will identify a number from left side which
     * is greater then the pivot value, and also we will identify a number
     * from right side which is less then the pivot value. Once the search
     * is done, then we exchange both numbers.
     */
    while (array[i] < pivot) {
      i++;
    }
    while (array[j] > pivot) {
      j--;
    }
    if (i <= j) {
      exchangeNumbers(i, j);
      //move index to next position on both sides
      i++;
      j--;
    }
  }
  // call quickSort() method recursively
  if (lowerIndex < j)
    quickSort(lowerIndex, j);
  if (i < higherIndex)
    quickSort(i, higherIndex);
}

void Quick::exchangeNumbers(size_t i, size_t j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
