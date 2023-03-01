#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

#include <map>
#include <memory>
#include <string>

class ObjectNode : public Node
{
private:
    std::map<std::string, NodePtr> _objectNode;

public:
    ObjectNode()
        : Node { NodeKind::OBJECT }
    {}

    ~ObjectNode() = default;

    std::string print() const override
    {
        bool        isFirst = true;
        std::string result  = "{";
        for (const auto& e : _objectNode)
        {
            if (!isFirst)
            {
                result += ",";
            }
            result += "\"" + e.first + "\":" + e.second->print();
            isFirst = false;
        }
        result += "}";
        return result;
    }

    size_t child_count() const { return _objectNode.size(); }

    void insert(const std::string& key, NodePtr value) { _objectNode.emplace(key, std::move(value)); }

    static std::unique_ptr<ObjectNode> make_ptr() { return std::make_unique<ObjectNode>(); }

    unsigned int height() const override
    {
        if (_objectNode.empty())
        {
            return 0;
        }
        unsigned int result = 0;
        for (const auto& node : _objectNode)
        {
            if (node.second->height() > result)
            {
                result = node.second->height();
            }
        }
        return result + 1;
    }

    unsigned int node_count() const override
    {
        unsigned int result = 0;
        for (const auto& node : _objectNode)
        {
            result += node.second->node_count();
        }
        return result + 1;
    }

    bool has_child(const std::string& key) const
    {
        if (auto search = _objectNode.find(key); search != _objectNode.end())
        {
            return true;
        }
        return false;
    }

    Node* at(const std::string& key) const;

    bool operator==(const Node& node) const override
    {
        auto value = node.as_ObjectNode();
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
