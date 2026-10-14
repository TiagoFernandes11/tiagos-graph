#pragma once

#include <string>
#include <utility>
#include <optional>
#include <map>
#include <cstdint>

class Relation
{
    public:
        Relation(std::uint64_t id, std::string label, std::string name, std::uint64_t from, std::uint64_t to);

        const std::uint64_t &id() const;
        const std::string &label() const;
        const std::string &name() const;
        const std::pair<std::uint64_t, std::uint64_t> &nodes() const;
        std::optional<std::string> property(const std::string &key) const;

        void setLabel(std::string label);
        void setName(std::string name); 
        void setProperty(const std::string &key, std::string value);

    private:
        const std::uint64_t id_;
        std::string label_;
        std::string name_;
        std::pair<std::uint64_t, std::uint64_t> nodes_;
        std::map<std::string, std::string> properties_;

        static std::string requireNonEmpty(std::string s, const char *field);
};