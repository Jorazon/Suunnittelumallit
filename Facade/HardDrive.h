#pragma once

#include "Block.h"

class HardDrive {
public:
  HardDrive() {
    // Initialize the hard drive data
    for (int i = 0; i < kHardDriveSize; i++) {
      data_[i] = 'A'+ i % 26;
    }
  }

  Block Read(long lba, int size) {
    char* result = new char[size];
    for (int i = 0; i < size; i++) {
      result[i] = data_[lba + i];
    }
    return Block(result, size);
  }

private:
  static const int kHardDriveSize = 1024;
  char data_[kHardDriveSize];
};
