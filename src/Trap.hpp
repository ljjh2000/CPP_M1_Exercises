#pragma once

#include <string>
#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

const std::string to_string(const TrapType cardType)
{
    switch (cardType)
    {
    case TrapType::Normal:
        return "Normal";

    case TrapType::Continuous:
        return "Continuous";

    case TrapType::Counter:
        return "Counter";

    default:
        return "";
    }
}

class Trap : public Card
{
public:
    Trap(const std::string &id, const std::string &name, const TrapType &trapType)
        : Card{id, CardType::Trap},
          _trapType{trapType}
    {
        Card::set_name(name);
    }

    const TrapType &get_trap_type() const
    {
        return _trapType;
    }

private:
    TrapType _trapType;
};
