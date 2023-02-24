#include "Node.hpp"

#include "IntLeaf.hpp"

IntLeaf* Node::as_IntLeaf()
{
    return dynamic_cast<IntLeaf*>(this);
}
