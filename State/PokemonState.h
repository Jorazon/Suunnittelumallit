#pragma once

#include <string>

#include "State.h"
#include "Pokemon.h"

class PokemonState : public State {
private:
  std::string name;
  int id;
  int max_hp;
  int hp;
  int attack;
  int defense;
  int xpToEvolve;
  PokemonState *evolution = nullptr;
public:
  PokemonState();
  PokemonState(std::string name, int id, int max_hp, int attack, int defense, int xpToEvolve);
  void SetEvolution(PokemonState* evolution);
  void Attack(PokemonState pokemon);
  void Defend(int damage);
  bool CheckEvolve(int xp, Context *context);
  friend std::ostream& operator<<(std::ostream& os, PokemonState state);
};

PokemonState::PokemonState() {
  name = "MissingNo.";
  id = 000;
  max_hp = 33;
  hp = max_hp;
  attack = 136;
  defense = 0;
  xpToEvolve = INT_MAX;
}

PokemonState::PokemonState(std::string name, int id, int max_hp, int attack, int defense, int xpToEvolve) {
  this->name = name;
  this->id = id;
  this->max_hp = max_hp;
  this->hp = max_hp;
  this->attack = attack;
  this->defense = defense;
  this->xpToEvolve = xpToEvolve;
}

void PokemonState::SetEvolution(PokemonState* evolution) {
  this->evolution = evolution;
}

void PokemonState:: Attack(PokemonState pokemon) {
  pokemon.Defend(attack);
}

void PokemonState:: Defend(int damage) {
  hp -= std::max(0, damage - defense);
  hp = std::max(0, hp);
}

bool PokemonState::CheckEvolve(int xp, Context *context) {
  if (xp >= xpToEvolve && evolution != nullptr) {
    context->changeState(evolution);
    return true;
  };
  return false;
}

std::ostream& operator<<(std::ostream& os, PokemonState state) {
  return os << state.name;
}
