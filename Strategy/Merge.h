#pragma once

#include "Sorter.h"

class Merge : public Sorter {
private:
  std::vector<int> array;
  std::vector<int> tempMergArr;
  size_t length = 0;
  void mergeParts(size_t lowerIndex, size_t middle, size_t higherIndex);
  void doMergeSort(size_t lowerIndex, size_t higherIndex);
public:
  void sort(std::vector<int>& array);
};

void Merge::doMergeSort(size_t lowerIndex, size_t higherIndex) {

  if (lowerIndex < higherIndex) {
    size_t middle = lowerIndex + (higherIndex - lowerIndex) / 2;
    // Below step sorts the left side of the array
    doMergeSort(lowerIndex, middle);
    // Below step sorts the right side of the array
    doMergeSort(middle + 1, higherIndex);
    // Now merge both sides
    mergeParts(lowerIndex, middle, higherIndex);
  }
}

void Merge::mergeParts(size_t lowerIndex, size_t middle, size_t higherIndex) {

  for (size_t i = lowerIndex; i <= higherIndex; i++) {
    tempMergArr[i] = array[i];
  }
  size_t i = lowerIndex;
  size_t j = middle + 1;
  size_t k = lowerIndex;
  while (i <= middle && j <= higherIndex) {
    if (tempMergArr[i] <= tempMergArr[j]) {
      array[k] = tempMergArr[i];
      i++;
    }
    else {
      array[k] = tempMergArr[j];
      j++;
    }
    k++;
  }
  while (i <= middle) {
    array[k] = tempMergArr[i];
    k++;
    i++;
  }
}

void Merge::sort(std::vector<int>& array) {
  this->array = array;
  this->length = array.size();
  this->tempMergArr.resize(length);
  doMergeSort(0, length - 1);
  array = this->array;
}
