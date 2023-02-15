#pragma warning(disable : 6031)

#include <iostream>

#include "Timer.h"
#include "Sorter.h"

#include "Radix.h"
#include "Insert.h"
#include "Merge.h"
#include "Quick.h"

const int N = 1000000;

int main() {
  std::cout << "Sorting array of " << N << std::endl;
  // generate and print unsorted array array
  std::vector<int> source(N);
  for (int i = 0; i < source.size(); ++i) {
    source[i] = std::rand() % 1000;
    //std::cout << source[i] << " ";
  }
  std::cout << std::endl;

  // create sorters
  Sorter* sort1 = new Insert();
  Sorter* sort2 = new Merge();
  Sorter* sort3 = new Radix();
  Sorter* sort4 = new Quick();

  // copy arrays
  std::vector<int> array1(source);
  std::vector<int> array2(source);
  std::vector<int> array3(source);
  std::vector<int> array4(source);

  // compare performance
  Timer timer; // start timer

  std::cout << "Insertion sort:\t";
  // Insertion sort is super slow
  //sort1->sort(array1);
  //std::cout << timer.elapsed() << " ms" << std::endl;
  std::cout << (int)(0.0012 * N + 0.00001 * N * N) << " ms" << std::endl; // estimate
  timer.reset();

  std::cout << "Merge sort:\t";
  sort2->sort(array2);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  std::cout << "Radix sort:\t";
  sort3->sort(array3);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  std::cout << "Quick sort:\t";
  sort4->sort(array4);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();
  /*
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
  */
  getchar();
}
