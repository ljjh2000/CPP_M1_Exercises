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
};
