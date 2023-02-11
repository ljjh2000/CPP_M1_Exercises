#pragma once

#include <array>
#include <string>
#include <memory>
#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"
#include "Pokedex.h"

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
        _pokedex.add(*pokemon);
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

    void store_in_pc(int index)
    {
        _pc.transfer(std::move(_pokeballs[index].extaxt()));
    }

    void fetch_from_pc(const std::string &name)
    {
        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                auto pokemon = _pc.remove(name, *this);
                if (pokemon == nullptr)
                {
                    return;
                }
                pokeball.store(std::move(pokemon));
                return;
            }
        }
    }

    const Pokedex &pokedex() const
    {
        return _pokedex;
    }

private:
    std::string _name;
    PC &_pc;
    std::array<Pokeball, 6> _pokeballs;
    Pokedex _pokedex;
};
