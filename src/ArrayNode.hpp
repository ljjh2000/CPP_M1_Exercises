#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

#include <string>
#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<Node> _nodes;

public:
    ArrayNode()
        : Node { NodeKind::ARRAY }
    {}
    ~ArrayNode() = default;

    std::string print() const override { return "[]"; }
};
