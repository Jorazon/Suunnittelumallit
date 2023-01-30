#pragma once

#include "FileReadWriteDecorator.h"
#include "Base64.h"

class EncryptedFileReadWrite : public virtual FileReadWriteDecorator {
public:
  EncryptedFileReadWrite(FileReadWrite* component);
  std::string read(std::string path);
  void write(std::string path, std::string data);
};

EncryptedFileReadWrite::EncryptedFileReadWrite(FileReadWrite* component) : FileReadWriteDecorator(component) {}

std::string EncryptedFileReadWrite::read(std::string path) {
  std::string data = component->read(path);
  return Base64::decode(data);
}

void EncryptedFileReadWrite::write(std::string path, std::string data) {
  component->write(path, Base64::encode(data));
}
