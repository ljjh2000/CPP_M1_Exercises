#pragma once

#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <memory>
#include <set>

class Kitchen
{
private:
    struct Comparator
    {
        bool isquals(const std::string& a, const std::string& b) const
        {
            return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
                                                [](char a, char b) { return tolower(a) < tolower(b); });
        }
        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
        bool operator()(const Ingredient& ingredient1, const Ingredient& ingredient2) const
        {
            return isquals(ingredient1.name, ingredient2.name);
        }
    };

    std::set<Unit, Comparator>       _set;
    std::set<Ingredient, Comparator> _ingredients;

public:
    const Unit& register_unit(Unit unit)
    {
        auto [s, b] = _set.emplace(std::move(unit));
        return *s;
    }

    const Unit* find_unit(const std::string& unit) const
    {
        auto newUnit = Unit { unit };
        auto search  = _set.find(newUnit);
        if (search != _set.end())
        {
            return &(*search);
        }
        return nullptr;
    }

    const Ingredient& register_ingredient(Ingredient ingredient)
    {
        auto [it, b] = _ingredients.emplace(std::move(ingredient));
        return *it;
    }

    const Ingredient* find_ingredient(const std::string& ingredient) const
    {
        auto newUnit       = Unit { " " };
        auto newIngredient = Ingredient { ingredient, newUnit };
        auto search        = _ingredients.find(newIngredient);
        if (search != _ingredients.end())
        {
            return &(*search);
        }
        return nullptr;
    }
};
