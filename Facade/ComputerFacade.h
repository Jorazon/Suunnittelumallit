#pragma once

#include "CPU.h"
#include "Memory.h"
#include "HardDrive.h"

class ComputerFacade {
public:
  void Start() {
    cpu_.Freeze();
    memory_.Load(kBootAddress, hard_drive_.Read(kBootSector, kSectorSize));
    cpu_.Jump(kBootAddress);
    for (size_t i = 0; i < kSectorSize; i++) {
      cpu_.Execute(&memory_);
    }
  }

private:
  CPU cpu_;
  Memory memory_;
  HardDrive hard_drive_;

  static const long kBootAddress = 961;
  static const long kBootSector = 7;
  static const int kSectorSize = 64;
};
