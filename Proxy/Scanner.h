#pragma once

template<typename T>
T getfromcin() {
  T get;
  std::cout << "\033[s";
  do {
    std::cin >> get;
    std::cout << "\033[u\033[K"; //clear line
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!std::cin.good()) getchar();
  } while (!std::cin.good());
  return get;
}
