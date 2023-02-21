#pragma once

#include <memory>
#include <vector>

#include "Card.hpp"

class Board
{
public:
    bool put(std::unique_ptr<Card> card)
    {
    }

private:
    std::vector<std::unique_ptr<Card>> _cards;
};
