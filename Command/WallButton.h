#pragma once

#include "Command.h"

class WallButton {
public:
  WallButton(Command* cmd) {
    command = cmd;
  }
  void push() {
    command->execute();
  }
private:
  Command* command;
};
