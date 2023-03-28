#pragma warning(disable : 6031)

#include <iostream>

#include "Clock.h"

int main() {
  // Create a clock and set the time
  Clock *originalClock = new Clock();
  originalClock->setTime(9, 30, 0);

  // Deep copy the clock
  Clock *DeepClock = originalClock->clone();
  
  // Shallow copy the clock
  Clock *ShallowClock = originalClock;

  // Print the times on all clocks
  std::cout << "Original clock:\t\t";
  originalClock->printTime();

  std::cout << "Deep Copy clock:\t";
  DeepClock->printTime();

  std::cout << "Shallow Copy clock:\t";
  ShallowClock->printTime();
  
  // Change the time on the original clock
  std::cout << "\nChange time on original clock\n\n";
  originalClock->setTime(10, 0, 0);

  // Print the times on all clocks again
  std::cout << "Original clock:\t\t";
  originalClock->printTime();

  std::cout << "Deep Copy clock:\t";
  DeepClock->printTime();

  std::cout << "Shallow Copy clock:\t";
  ShallowClock->printTime();

  getchar();
}
