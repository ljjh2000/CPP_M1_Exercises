#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
private:
    int _nb;

public:
    IntLeaf(int nb)
        : Leaf { NodeKind::INT }
        , _nb { nb }
    {}

    std::string print() const override { return std::to_string(_nb); }

    int data() const { return _nb; }
};
