#pragma warning(disable : 6031)

#include <iostream>

#include "Screen.h"
#include "ScreenButtonCommands.h"
#include "WallButton.h"

int main() {
  Screen screen;
  
  UpCommand upCommand(&screen);
  DownCommand downCommand(&screen);

  WallButton upButton(&upCommand);
  WallButton downButton(&downCommand);

  downButton.push();
  downButton.push();

  upButton.push();
  upButton.push();

  downButton.push();

  upButton.push();
  
  getchar();
}
