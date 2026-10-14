#pragma once

#include <map>
#include <optional>
#include <string>
#include <cstdint>

class Node
{
public:
    Node(std::uint64_t id, std::string label, std::string name);

    const std::uint64_t &id() const;
    const std::string &label() const;
    const std::string &name() const;

    void setLabel(std::string label);
    void setName(std::string name);

    std::optional<std::string> property(const std::string &key) const;

    void setProperty(const std::string &key, std::string value);

private:
    const std::uint64_t id_;
    std::string label_;
    std::string name_;
    std::map<std::string, std::string> properties_;

    static std::string requireNonEmpty(std::string s, const char *field);
};
