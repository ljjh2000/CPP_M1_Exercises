#pragma once

#include <array>
#include <string>
#include <memory>
#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc)
        : _name{name}, _pc{pc}
    {
    }

    const std::string &name() const
    {
        return _name;
    }

    const std::array<Pokeball, 6> &pokeballs() const
    {
        return _pokeballs;
    }

    void capture(PokemonPtr pokemon)
    {
        pokemon->set_trainer(*this);
        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                pokeball.store(std::move(pokemon));
                return;
            }
        }
        _pc.transfer(std::move(pokemon));
    }

private:
    std::string _name;
    PC &_pc;
    std::array<Pokeball, 6> _pokeballs;
};
