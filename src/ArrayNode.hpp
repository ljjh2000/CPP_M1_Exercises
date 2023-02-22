#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>
#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<NodePtr> _arrayNodes;

public:
    ArrayNode()
        : Node { NodeKind::ARRAY }
    {}
    ~ArrayNode() = default;

    std::string print() const override { return "[]"; }

    void push_back(NodePtr arrayNode) { _arrayNodes.emplace_back(std::move(arrayNode)); }

    int child_count() const { return InstanceCounter::counter(); }

    static std::unique_ptr<ArrayNode> make_ptr() { return std::make_unique<ArrayNode>(); }
};
