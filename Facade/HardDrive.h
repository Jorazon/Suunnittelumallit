#pragma once

#include "Block.h"

/**
 * @brief Slow data storage
*/
class HardDrive {
public:
  HardDrive();
  Block Read(long lba, int size);

private:
  static const int HardDriveSize_ = 1024;
  char data_[HardDriveSize_];
};

HardDrive::HardDrive() {
  // Initialize the hard drive data
  for (int i = 0; i < HardDriveSize_; i++) {
    data_[i] = 'A' + i % 26;
  }
}

/**
 * @brief Reads a number of logical blocks from the drive
 * @param lba Block index
 * @param size Number of blocks
 * @return Data
*/
Block HardDrive::Read(long lba, int size) {
  char* result = new char[size];
  for (int i = 0; i < size; i++) {
    result[i] = data_[lba + i];
  }
  return Block(result, size);
}
