#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

#include <memory>
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

    static std::unique_ptr<ObjectNode> make_ptr() { return std::make_unique<ObjectNode>(); }
};
