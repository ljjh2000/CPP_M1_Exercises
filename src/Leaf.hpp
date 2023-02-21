#pragma once

#include "Node.hpp"

class Leaf : public Node
{
protected:
    Leaf(NodeKind nodeKind)
        : Node { nodeKind }
    {}

public:
    virtual ~Leaf() = default;
};
