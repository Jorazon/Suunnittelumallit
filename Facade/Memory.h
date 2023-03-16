#pragma once

#include <iostream>

#include "Block.h"

/**
 * @brief Fast data storage
*/
class Memory {
public:
  Memory();
  void Load(long position, Block block);
  char GetByte(long position);

private:
  static const int kMemorySize = 1024;
  static const int kDataSize = 512;
  char data_[kMemorySize];
};

Memory::Memory() {
  // Initialize the memory data
  for (int i = 0; i < kMemorySize; i++) {
    data_[i] = '0';
  }
}

/**
 * @brief Load data block into memory at a specified position 
 * @param position
 * @param block
*/
void Memory::Load(long position, Block block) {
  for (size_t i = 0; i < block.size_; i++) {
    if (position + i < kMemorySize) {
      data_[position + i] = block.data_[i];
    }
    else {
      std::cout << "Out of memory\n";
      break;
    }
  }
}

/**
 * @brief Read a byte from a position in memory
 * @param position 
 * @return byte
*/
char Memory::GetByte(long position) {
  if (position < kMemorySize) {
    return data_[position];
  }
  else {
    std::cout << "Memory address out of range";
    return '\0';
  }
}
