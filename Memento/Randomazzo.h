#pragma once

#include "Random.h"

class Randomazzo {
public:
  class Memento;
  bool ValidateGuess(int guess, void* memento);
  Memento* Join();
};

class Randomazzo::Memento {
private:
  Memento(int answer);
  int answer;
  friend Randomazzo;
};

bool Randomazzo::ValidateGuess(int guess, void* memento) {
  return guess == ((Memento*)memento)->answer;
}

Randomazzo::Memento* Randomazzo::Join() {
  int answer = Random::Generate();
  return new Memento(answer);
}

Randomazzo::Memento::Memento(int answer) {
  this->answer = answer;
}
