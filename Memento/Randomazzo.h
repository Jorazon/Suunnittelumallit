#pragma once

#include "Random.h"

class Randomazzo {
private:
  class Memento;
public:
  bool ValidateGuess(int guess, void* memento);
  void* Join();
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

void* Randomazzo::Join() {
  int answer = Random::Generate();
  return new Memento(answer);
}

Randomazzo::Memento::Memento(int answer) {
  this->answer = answer;
}
