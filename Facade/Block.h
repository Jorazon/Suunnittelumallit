#pragma once

/**
 * @brief Array with size
*/
class Block {
public:
  const char *data_;
  const size_t size_;
  Block(char* data, size_t size) :
    data_(data), size_(size) {};
};
