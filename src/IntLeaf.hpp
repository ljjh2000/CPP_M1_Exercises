#pragma once

#include "Leaf.hpp"
#include "Node.hpp"
#include "NodeKind.hpp"

#include <memory>
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

    static std::unique_ptr<IntLeaf> make_ptr(int nb) { return std::make_unique<IntLeaf>(nb); }

    unsigned int height() const override { return 0; }

    unsigned int node_count() const override { return 1; }

    bool operator==(const Node& node) const override
    {
        auto intLeaf = node.as_IntLeaf();
        if (intLeaf == nullptr)
        {
            return false;
        }
        if (intLeaf->print() == print())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
