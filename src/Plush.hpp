#pragma once

class Plush
{
public:
    Plush()
        : _cost{10}
    {
    }

    Plush(int cost)
        : _cost{cost}
    {
    }

    int get_cost() const
    {
        return _cost;
    }

    void set_cost(int cost)
    {
        _cost = cost;
    }

private:
    int _cost;
};