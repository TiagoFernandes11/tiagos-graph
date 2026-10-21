#pragma once

#include <string>
#include <cstdint>

class Node
{
    private:
        const std::uint64_t id_;
        std::string label_;
        std::string name_;
        
    public:
        Node(std::uint64_t id, std::string label, std::string name);

        const std::uint64_t &id() const;
        const std::string &label() const;
        const std::string &name() const;

        void setLabel(std::string label);
        void setName(std::string name);
};
