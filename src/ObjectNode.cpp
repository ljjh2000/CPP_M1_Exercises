#include "ObjectNode.hpp"

#include "Node.hpp"

Node* ObjectNode::at(std::string const& key) const
{
    if (has_child(key))
        return _objectNode.at(key).get();
    else
        return nullptr;
}