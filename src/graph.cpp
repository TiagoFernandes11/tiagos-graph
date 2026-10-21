#include "graph.hpp"

Graph::Graph(std::uint64_t id, std::string label, std::string name) : id_(id), label_(label), name_(name) {}

const std::uint64_t &Graph::id() const {return id_;}
const std::string &Graph::label() const { return label_; }
const std::string &Graph::name() const { return name_; }

void Graph::setLabel(std::string label) { label_ = label; }
void Graph::setName(std::string name) { name_ = name; }