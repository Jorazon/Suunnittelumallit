#pragma warning(disable : 6031)

#include <iostream>

#include "Timer.h"
#include "Sorter.h"
#include "Context.h"

#include "Radix.h"
#include "Insert.h"
#include "Merge.h"
#include "Quick.h"

const int N = 3000000;

int main() {
  std::cout << "Sorting array of " << N << std::endl;

  std::srand(1);

  // generate and print unsorted array array
  std::vector<int> source(N);
  for (int i = 0; i < source.size(); ++i) {
    source[i] = std::rand() % 1000;
    //std::cout << source[i] << " "; // print array
  }
  std::cout << std::endl;

  Context context;

  // copy arrays
  std::vector<int> array1(source);
  std::vector<int> array2(source);
  std::vector<int> array3(source);
  std::vector<int> array4(source);

  // compare performance
  Timer timer; // start timer

  std::cout << "Insertion sort:\t";
  // Insertion sort is super slow
  //context.SetStrategy(new Insert());
  //context.sort(array1);
  //std::cout << timer.elapsed() << " ms" << std::endl;
  std::cout << (int)(1e-5 * N * N + 1e-3 * N) << " ms" << std::endl; // estimate
  timer.reset();

  std::cout << "Merge sort:\t";
  context.SetStrategy(new Merge());
  context.sort(array2);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  std::cout << "Quick sort:\t";
  context.SetStrategy(new Quick());
  context.sort(array3);
  std::cout << timer.elapsed() << " ms" << std::endl;
  timer.reset();

  std::cout << "Radix sort:\t";
  context.SetStrategy(new Radix());
  context.sort(array4);
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
