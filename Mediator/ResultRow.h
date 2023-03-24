#pragma once

#include <string>

class ResultRow {
public:
  void display(std::string name, float totalScore) {
    printf("%s\t%.1f\n", name.c_str(), totalScore);
  }
};
