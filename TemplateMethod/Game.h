#pragma once

class Game {
protected:
  int playersCount = -1;
public:
  virtual void initializeGame() = 0;
  virtual void makePlay(int player) = 0;
  virtual bool endOfGame() = 0;
  virtual void printWinner() = 0;
  void playOneGame(int playersCount);
};

void Game::playOneGame(int playersCount) {
  this->playersCount = playersCount;
  initializeGame();
  int j = 0;
  while (!endOfGame()) {
    makePlay(j);
    j = ++j % playersCount;
  }
  printWinner();
  getchar();
}
