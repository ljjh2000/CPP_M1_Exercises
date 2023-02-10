#pragma once

#include <vector>
#include <memory>
#include "Pokeball.h"
#include "Pokemon.h"

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    const std::vector<PokemonPtr> &pokemons() const
    {
        return _pokemons;
    }

    void transfer(PokemonPtr pokemon)
    {
        _pokemons.emplace_back(std::move(pokemon));
    }

private:
    std::vector<PokemonPtr> _pokemons;
};
