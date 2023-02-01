#pragma once
#include <string>
#include <optional>
#include <algorithm>
#include <vector>
#include "Plush.hpp"
#include <iostream>

class PlushStore
{
public:
    PlushStore(const std::string &name)
        : _name{name}
    {
    }

    std::string get_name() const
    {
        return _name;
    }

    int get_stock_size() const
    {
        return _stock.size();
    }

    int get_wealth_amount() const
    {
        return _wealth_amount;
    }

    void loan(int wealth_amount)
    {
        _wealth_amount += wealth_amount;
    }

    int get_debt_amount() const
    {
        return _wealth_amount + (_wealth_amount / 10);
    }

    int make_plush(int nb)
    {
        _experience++;
        auto value = nb + std::max(_experience, (_experience * nb) / 100);
        if (_wealth_amount != 0)
        {
            _size++;
            _wealth_amount -= nb;
            if (_wealth_amount < 0)
            {
                _wealth_amount = 0;
            }
            _stock.push_back(Plush{value});
        }

        return value;
    }

    int get_experience() const
    {
        return _experience;
    }

    std::optional<Plush> buy(int price)
    {

        auto plush = _stock.end();
        for (auto it = _stock.begin(); it != _stock.end(); ++it)
        {

            if (it->get_cost() == price)
            {
                return *it;
            }
            if (it->get_cost() < price && (plush == _stock.end() || it->get_cost() < plush->get_cost()))
            {
                plush = it;
            }
        }

        if (plush == _stock.end())
        {
            return std::nullopt;
        }
        else
        {
            auto p = *plush;
            (_stock.erase(plush));
            _wealth_amount += p.get_cost();

            return p;
        }
    }

private:
    const std::string _name;
    int _size = 0;
    int _wealth_amount = 0;
    int _experience = 0;
    std::vector<Plush> _stock;
};