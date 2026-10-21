#include <string>
#include "node.hpp"

Node::Node(std::uint64_t id, std::string label, std::string name) : id_(id), label_(label), name_(name){}

const std::uint64_t &Node::id() const {return id_;}
const std::string &Node::label() const { return label_; }
const std::string &Node::name() const { return name_; }

void Node::setLabel(std::string label) { label_ = label; }
void Node::setName(std::string name) { name_ = name; }
