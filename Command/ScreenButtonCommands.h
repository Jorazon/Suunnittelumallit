#pragma once

#include "Command.h"
#include "Screen.h"

class UpCommand : public Command {
public:
  UpCommand(Screen* screen) {
    this->screen = screen;
  }
  void execute() override {
    screen->GoUp();
  }
private:
  Screen* screen;
};

class DownCommand : public Command {
public:
  DownCommand(Screen* screen) {
    this->screen = screen;
  }
  void execute() override {
    screen->GoDown();
  }
private:
  Screen* screen;
};
