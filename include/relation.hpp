#pragma once

#include <string>
#include <utility>
#include <cstdint>

class Relation
{
    
    private:
        const std::uint64_t id_;
        std::string label_;
        std::string name_;
        std::pair<std::uint64_t, std::uint64_t> nodes_;

    public:
        Relation(std::uint64_t id, std::string label, std::string name, std::uint64_t from, std::uint64_t to);

        const std::uint64_t &id() const;
        const std::string &label() const;
        const std::string &name() const;
        const std::pair<std::uint64_t, std::uint64_t> &nodes() const;

        void setLabel(std::string label);
        void setName(std::string name);
};