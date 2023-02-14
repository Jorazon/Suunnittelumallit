#pragma warning(disable : 6031)

#include <iostream>

#include "Timer.h"
#include "Sorter.h"

#include "Radix.h"
#include "Insert.h"
#include "Merge.h"
#include "Quick.h"

int main() {
  // generate and print unsorted array array
  std::vector<int> source(30);
  for (int i = 0; i < source.size(); ++i) {
    source[i] = std::rand() % 1000;
    std::cout << source[i] << " ";
  }
  std::cout << std::endl;

  // create sorters
  Sorter* sort1 = new Radix();
  Sorter* sort2 = new Insert();
  Sorter* sort3 = new Merge();
  Sorter* sort4 = new Quick();

  // copy arrays
  std::vector<int> array1(source);
  std::vector<int> array2(source);
  std::vector<int> array3(source);
  std::vector<int> array4(source);

  // compare performance
  Timer timer; // start timer

  std::cout << "Radix sort:\t";
  sort1->sort(array1);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  std::cout << "Insertion sort:\t";
  sort2->sort(array2);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  std::cout << "Merge sort:\t";
  sort3->sort(array3);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  std::cout << "Quick sort:\t";
  sort4->sort(array4);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  // print sorted arrays
  for (int i : array1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for (int i : array2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for (int i : array3) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for (int i : array4) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  getchar();
}
