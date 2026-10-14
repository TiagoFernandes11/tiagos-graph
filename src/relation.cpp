#include "relation.hpp"
#include <stdexcept>
#include <string>
#include <utility>

Relation::Relation(std::uint64_t id, std::string label, std::string name, std::uint64_t from, std::uint64_t to)
    : id_(id),
      label_(requireNonEmpty(std::move(label), "label")),
      name_(requireNonEmpty(std::move(name), "name")),
      nodes_(from, to) {}

const std::uint64_t &Relation::id() const {
    return id_;
}

const std::string &Relation::label() const {
    return label_;
};

const std::string &Relation::name() const {
    return name_;
};

const std::pair<std::uint64_t, std::uint64_t> &Relation::nodes() const {
    return nodes_;
}

void Relation::setLabel(std::string label) {
    label_ = requireNonEmpty(std::move(label), "label");
}

void Relation::setName(std::string name) {
    name_ = requireNonEmpty(std::move(name), "name");
}

std::optional<std::string> Relation::property(const std::string &key) const
{
    auto it = properties_.find(key);

    if (it == properties_.end()) return std::nullopt;

    return it->second;
}

void Relation::setProperty(const std::string &key, std::string value)
{
    properties_.insert_or_assign(key, std::move(value));
}

std::string Relation::requireNonEmpty(std::string s, const char *field)
{
    if (s.empty()) throw std::invalid_argument(std::string(field) + " must not be empty");
    return s;
}