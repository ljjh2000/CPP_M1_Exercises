#include "Node.hpp"

#include "IntLeaf.hpp"
#include "StringLeaf.hpp"

IntLeaf* Node::as_IntLeaf()
{
    return dynamic_cast<IntLeaf*>(this);
}

StringLeaf* Node::as_StringLeaf()
{
    return dynamic_cast<StringLeaf*>(this);
}
