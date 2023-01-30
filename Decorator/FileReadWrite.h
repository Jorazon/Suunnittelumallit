#pragma once

#include <string>
#include <iostream>
#include <fstream>

class FileReadWrite {
public:
  virtual std::string read(std::string path) = 0;
  virtual void write(std::string path, std::string data) = 0;
};