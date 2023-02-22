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

    std::string print() const override
    {
        std::string result = "[";
        for (size_t i = 0; i < _arrayNodes.size(); i++)
        {
            result += _arrayNodes[i]->print();
            if (i != _arrayNodes.size() - 1)
            {
                result += ",";
            }
        }
        result += "]";
        return result;
    }

    void push_back(NodePtr arrayNode) { _arrayNodes.emplace_back(std::move(arrayNode)); }

    size_t child_count() const { return _arrayNodes.size(); }

    static std::unique_ptr<ArrayNode> make_ptr() { return std::make_unique<ArrayNode>(); }
};
