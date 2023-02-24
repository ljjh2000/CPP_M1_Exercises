#pragma once

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class IntLeaf;
class StringLeaf;
class ArrayNode;

class Node;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
protected:
    Node(NodeKind nodeKind)
        : _nodeKind { nodeKind }
    {}

private:
    NodeKind _nodeKind;

public:
    virtual ~Node() = default;

    virtual std::string print() const = 0;

    virtual unsigned int height() const = 0;

    virtual unsigned int node_count() const = 0;

    NodeKind kind() const { return _nodeKind; }

    IntLeaf* as_IntLeaf();

    StringLeaf* as_StringLeaf();

    ArrayNode* as_ArrayNode();
};
