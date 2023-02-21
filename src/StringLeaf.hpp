#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class StringLeaf : public Leaf
{
private:
    std::string _chaine;

public:
    StringLeaf(const std::string& chaine)
        : Leaf { NodeKind::STRING }
        , _chaine { chaine }
    {}

    std::string print() const override { return "\"" + _chaine + "\""; }

    std::string data() const { return _chaine; }

    ~StringLeaf() = default;
};
