#pragma once

#include <vector>
#include <memory>
#include "Pokeball.h"
#include "Pokemon.h"

class Trainer;

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

    PokemonPtr remove(const std::string &name, const Trainer &trainer)
    {
        for (auto it = _pokemons.begin(); it != _pokemons.end();)
        {
            if ((*it)->name() == name && (*it)->trainer() == &trainer)
            {
                auto pokemon = std::move(*it);

                it = _pokemons.erase(it);
                return pokemon;
            }
            else
            {
                it++;
            }
        }
        return nullptr;
    }

private:
    std::vector<PokemonPtr> _pokemons;
};
