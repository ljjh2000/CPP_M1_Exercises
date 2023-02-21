#pragma once

#include "InstanceCounter.hpp"

class Node : public InstanceCounter
{
protected:
    Node();

private:
public:
    virtual ~Node();
};
