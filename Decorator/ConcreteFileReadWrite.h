#pragma once

#include "FileReadWrite.h"

class ConcreteFileReadWrite : public virtual FileReadWrite {
public:
  std::string read(std::string path);
  void write(std::string path, std::string data);
};

std::string ConcreteFileReadWrite::read(std::string path) {

  std::ifstream file;
  file.open(path);
  std::string ret, line;
  if (file.is_open()) {
    while (std::getline(file, line)) {
      ret.append(line);
    }
    file.close();
  } else printf("Couldn't open file: %s\n", path.c_str());
  return ret;
}

void ConcreteFileReadWrite::write(std::string path, std::string data) {
  std::ofstream file;
  file.open(path);
  if (file.is_open()) {
    file << data;
    file.close();
  } else printf("Couldn't open file: %s\n", path.c_str());
}
