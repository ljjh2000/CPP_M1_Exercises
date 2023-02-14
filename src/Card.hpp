#pragma once

#include <string>

enum class CardType
{
    Monster,
    Spell,
    Trap
};

const std::string to_string(const CardType cardType)
{
    switch (cardType)
    {
    case CardType::Monster:
        return "Monster";

    case CardType::Spell:
        return "Spell";

    case CardType::Trap:
        return "Trap";

    default:
        return "";
    }
}

class Card
{
public:
    Card(const std::string &id, const CardType &cardType)
        : _id{id},
          _cardType{cardType}
    {
    }

    const std::string &get_id() const
    {
        return _id;
    }

    const CardType &get_type() const
    {
        return _cardType;
    }

    void set_name(const std::string &name)
    {
        _name = name;
    }

    const std::string &get_name() const
    {
        return _name;
    }

    void set_description(const std::string &description)
    {
        _description = description;
    }

    const std::string &get_description() const
    {
        return _description;
    }

    const std::string &get_symbol() const
    {
        return _symbol;
    }

private:
    std::string _id;
    CardType _cardType;
    std::string _name;
    std::string _description;

protected:
    std::string _symbol;
};
