#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <memory>
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

    static std::unique_ptr<StringLeaf> make_ptr(const std::string& chaine)
    {
        return std::make_unique<StringLeaf>(chaine);
    }

    unsigned int height() const override { return 0; }

    unsigned int node_count() const override { return 1; }

    bool operator==(const Node& node) const override
    {
        auto value = node.as_StringLeaf();
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
