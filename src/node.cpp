#include <optional>
#include <stdexcept>
#include <string>
#include "node.hpp"

const std::string &Node::label() const { return label_; }
const std::string &Node::name() const { return name_; }

void Node::setLabel(std::string label) { label_ = requireNonEmpty(std::move(label), "label"); }
void Node::setName(std::string name) { name_ = requireNonEmpty(std::move(name), "name"); }

std::optional<std::string> Node::property(const std::string &key) const
{
    auto it = properties_.find(key);

    if (it == properties_.end())
        return std::nullopt;

    return it->second;
}

void Node::setProperty(const std::string &key, std::string value)
{
    properties_.insert_or_assign(key, std::move(value));
}

std::string Node::requireNonEmpty(std::string s, const char *field)
{
    if (s.empty())
        throw std::invalid_argument(std::string(field) + " must not be empty");
    return s;
}
