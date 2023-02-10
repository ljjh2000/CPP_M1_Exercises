#pragma once

#include "Pokemon.h"
#include <memory>

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const
    {
        return _pokemon == nullptr;
    }

    void store(PokemonPtr pokemon)
    {
        _pokemon = std::move(pokemon);
    }

    const Pokemon &pokemon()
    {
        return *_pokemon;
    }

private:
    PokemonPtr _pokemon;
};
