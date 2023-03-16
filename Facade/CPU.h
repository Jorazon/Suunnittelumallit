#pragma once

#include <iostream>

#include "Memory.h"

/**
 * @brief Instruction executor
*/
class CPU {
public:
  CPU() : instruction_pointer_(0) {}

  void Freeze() {
    std::cout << "CPU Freeze\n";
  }
  void Jump(long position) {
    instruction_pointer_ = position;
    std::cout << "CPU Jump to position " << position << "\n";
  }
  void Execute(Memory* memory) {
    char instruction = memory->GetByte(instruction_pointer_);
    std::cout << "CPU Execute instruction " << instruction_pointer_ << ":\t" << instruction << "\n";
    instruction_pointer_++;
  }
  long GetInstructionPointer() {
    return instruction_pointer_;
  }
  char GetInstruction(char* memory_data) {
    return memory_data[instruction_pointer_];
  }

private:
  long instruction_pointer_;
};
