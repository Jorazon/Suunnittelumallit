#pragma warning(disable : 6031)

#include <iostream>

#include "Pokemon.h"
#include "PokemonState.h"

int main() {
  
  PokemonState* charmander1 = new PokemonState("Charmander", 004, 39, 52, 43, 62);
  PokemonState* charmeleon1 = new PokemonState("Charmeleon", 005, 58, 64, 58, 142);
  PokemonState* charizard1 = new PokemonState("Charizard", 006, 78, 84, 78, 267);

  charmander1->SetEvolution(charmeleon1);
  charmeleon1->SetEvolution(charizard1);
  
  PokemonState* charmander2 = new PokemonState("Charmander", 004, 39, 52, 43, 62);
  PokemonState* charmeleon2 = new PokemonState("Charmeleon", 005, 58, 64, 58, 142);
  PokemonState* charizard2 = new PokemonState("Charizard", 006, 78, 84, 78, 267);

  charmander2->SetEvolution(charmeleon2);
  charmeleon2->SetEvolution(charizard2);

  Pokemon pokemon1("pokemon1");
  Pokemon pokemon2("pokemon2");

  pokemon1.changeState(charmander1);
  pokemon2.changeState(charmander2);

  for (int i = 0; i < 142; ++i) {
    pokemon1.Attack(pokemon2);
    pokemon2.Attack(pokemon1);
  }

  getchar();
}
