#pragma once

#include <thread>

#include "Randomazzo.h"
#include "Random.h"

class Guesser {
public:
  Guesser(Randomazzo& randomazzo);
  void Start() {
    std::thread T1(&Guesser::Task, this);
    thread = &T1;
    thread->detach();
  }
  void Stop() {
    if (thread) thread->~thread();
  }
private:
  Randomazzo* randomazzo;
  void Task();
  std::thread* thread = nullptr;
  Randomazzo::Memento *memento = nullptr;
};

Guesser::Guesser(Randomazzo& randomazzo) {
  this->randomazzo = &randomazzo;
  this->memento = randomazzo.Join();
}

void Guesser::Task() {
  for (;;) { 
    int guess = Random::Generate();
    if (randomazzo->ValidateGuess(guess, memento)) {
      printf("%X guessed right. Answer was %i.\n", (int)this, guess);
      break;
    }
  }
}
