#pragma once

#include <string>

#include "Context.h"
#include "PokemonState.h"

class Pokemon : public Context {
private:
  std::string name;
  int xp;
protected:
  void Defend(int damage) { ((PokemonState*)state)->Defend(damage); }
public:
  Pokemon();
  Pokemon(std::string name);
  void Attack(Pokemon other);
  int GetXP() { return xp; }
  friend std::ostream& operator<<(std::ostream& os, Pokemon context);
};

Pokemon::Pokemon() {
  name = "";
}

Pokemon::Pokemon(std::string name) {
  this->name = name;
}

void Pokemon::Attack(Pokemon other) {
  std::cout << *this << " attacks.\n";
  ((PokemonState*)state)->Attack(*(PokemonState*)other.state);
  if (((PokemonState*)state)->CheckEvolve(++xp)) {
    std::cout << *this << " evolves to " << *(PokemonState*)state << ".\n";
  }
}

std::ostream& operator<<(std::ostream& os, Pokemon context) {
  if (context.name.empty()) {
    return os << *(PokemonState*)context.state;
  }
  return os << context.name;
}
