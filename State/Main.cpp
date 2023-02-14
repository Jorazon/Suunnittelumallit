#pragma warning(disable : 6031)

#include <iostream>

#include "Pokemon.h"
#include "PokemonState.h"

int main() {
  
  PokemonState* charmander = new PokemonState("Charmander", 004, 39, 52, 43, 62);
  PokemonState* charmeleon = new PokemonState("Charmeleon", 005, 58, 64, 58, 142);
  PokemonState* charizard = new PokemonState("Charizard", 006, 78, 84, 78, 267);

  charmander->SetEvolution(charmeleon);
  charmeleon->SetEvolution(charizard);

  Pokemon pokemon1("pokemon1");
  Pokemon pokemon2("pokemon2");

  pokemon1.changeState(charmander);
  pokemon2.changeState(charmander);

  for (int i = 0; i < 142; ++i) {
    pokemon1.Attack(pokemon2);
    pokemon2.Attack(pokemon1);
  }

  getchar();
}
