#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

#include <string>
#include <vector>

class ObjectNode : public Node
{
private:
    /* data */
public:
    ObjectNode()
        : Node { NodeKind::OBJECT }
    {}

    ~ObjectNode() = default;

    std::string print() const override { return "{}"; }
};
