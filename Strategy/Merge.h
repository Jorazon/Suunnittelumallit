#pragma once

#include "Sorter.h"

class Merge : public Sorter {
private:
  std::vector<int> array;
  std::vector<int> tempMergArr;
  int length;
  void mergeParts(int lowerIndex, int middle, int higherIndex);
  void doMergeSort(int lowerIndex, int higherIndex);
public:
  void sort(std::vector<int>& array);
};

void Merge::doMergeSort(int lowerIndex, int higherIndex) {

  if (lowerIndex < higherIndex) {
    int middle = lowerIndex + (higherIndex - lowerIndex) / 2;
    // Below step sorts the left side of the array
    doMergeSort(lowerIndex, middle);
    // Below step sorts the right side of the array
    doMergeSort(middle + 1, higherIndex);
    // Now merge both sides
    mergeParts(lowerIndex, middle, higherIndex);
  }
}

void Merge::mergeParts(int lowerIndex, int middle, int higherIndex) {

  for (int i = lowerIndex; i <= higherIndex; i++) {
    tempMergArr[i] = array[i];
  }
  int i = lowerIndex;
  int j = middle + 1;
  int k = lowerIndex;
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
