#pragma once

#include <string>
#include <iostream>
#include <memory>

static int ID = 0;

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string &name)
        : _name{name},
          _id{ID}

    {
        ID++;
    }

    Pokemon(const Pokemon &pokemon)
        : _name{pokemon.name()},
          _id{ID}

    {
        ID++;
    }

    const std::string &name() const
    {
        return _name;
    }

    int id() const
    {
        return _id;
    }

    const Trainer *trainer() const
    {
        return _trainer;
    }

    void set_trainer(const Trainer &trainer)
    {
        _trainer = &trainer;
    }

    Pokemon operator=(const Pokemon pokemon)
    {
        return Pokemon{pokemon};
    }

private:
    const std::string _name;
    int _id;
    const Trainer *_trainer = nullptr;
};

using PokemonPtr = std::unique_ptr<Pokemon>;
