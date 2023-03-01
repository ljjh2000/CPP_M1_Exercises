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

    unsigned int height() const override
    {
        if (_arrayNodes.empty())
        {
            return 0;
        }
        unsigned int result = 0;
        for (const auto& node : _arrayNodes)
        {
            if (node->height() > result)
            {
                result = node->height();
            }
        }
        return result + 1;
    }

    unsigned int node_count() const override
    {
        unsigned int result = 0;
        for (const auto& node : _arrayNodes)
        {
            result += node->node_count();
        }
        return result + 1;
    }

    std::vector<NodePtr>::iterator begin() { return _arrayNodes.begin(); }

    std::vector<NodePtr>::iterator end() { return _arrayNodes.end(); }

    std::vector<NodePtr>::const_iterator begin() const { return _arrayNodes.begin(); }

    std::vector<NodePtr>::const_iterator end() const { return _arrayNodes.end(); }

    bool operator==(const Node& node) const override
    {
        auto value = node.as_ArrayNode();
        if (value == nullptr)
        {
            return false;
        }
        if (value->print() == print())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
