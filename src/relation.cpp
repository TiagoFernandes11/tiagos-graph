#include "node.hpp"
#include "relation.hpp"

Relation::Relation(std::uint64_t id, std::string label, std::string name, Node* from, Node* to)
    : id_(id),
      label_(label),
      name_(name),
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

const std::pair<Node*, Node*> &Relation::nodes() const {
    return nodes_;
}

void Relation::setLabel(std::string label) {
    label_ = label;
}

void Relation::setName(std::string name) {
    name_ = name;
}