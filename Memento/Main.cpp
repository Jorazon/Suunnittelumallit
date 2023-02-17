#pragma warning(disable : 6031)

#include <iostream>

#include "Randomazzo.h"
#include "Guesser.h"

int main() {

  Randomazzo randyrandom;

  Guesser* guessers[1000];

  for (Guesser* guesser : guessers) {
    guesser = new Guesser(randyrandom);
    guesser->Start();
  }

  getchar();
}
