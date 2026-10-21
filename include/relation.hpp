#pragma once

#include <string>
#include <utility>
#include <cstdint>

#include "node.hpp"

class Relation
{
    
    private:
        const std::uint64_t id_;
        std::string label_;
        std::string name_;
        std::pair<Node*, Node*> nodes_;

    public:
        Relation(std::uint64_t id, std::string label, std::string name, Node *from, Node *to);

        const std::uint64_t &id() const;
        const std::string &label() const;
        const std::string &name() const;
        const std::pair<Node*, Node*> &nodes() const;

        void setLabel(std::string label);
        void setName(std::string name);
};