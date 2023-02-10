#pragma once

#include <string>
#include "PC.h"

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

private:
    std::string _name;
    PC &_pc;
};
