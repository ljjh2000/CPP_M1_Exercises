#pragma once

#include <map>
#include <string>
#include <vector>
#include "Pokemon.h"

class Pokedex
{
public:
    void add(const Pokemon &pokemon)
    {
        _map[pokemon.name()].emplace_back(&pokemon);
    }

    const std::vector<const Pokemon *> &find(const std::string &name) const
    {
        auto vector = _map.find(name);
        if (vector == _map.end())
        {
            return _vector;
        }
        else
        {
            return vector->second;
        }
    }

private:
    std::vector<const Pokemon *> _vector;
    std::map<std::string, std::vector<const Pokemon *>>
        _map;
};
