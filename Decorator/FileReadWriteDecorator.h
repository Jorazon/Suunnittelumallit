#pragma once

#include <string>

#include "FileReadWrite.h"

class FileReadWriteDecorator : public FileReadWrite {
protected:
  FileReadWrite* component;
public:
  FileReadWriteDecorator(FileReadWrite* component);
  virtual std::string read(std::string path);
  virtual void write(std::string path, std::string data);
};

FileReadWriteDecorator::FileReadWriteDecorator(FileReadWrite* component) {
  this->component = component;
}

std::string FileReadWriteDecorator::read(std::string path) {
  return component->read(path);
}

void FileReadWriteDecorator::write(std::string path, std::string data) {
  component->write(path, data);
}
