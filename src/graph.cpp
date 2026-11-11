#include "graph.hpp"

Graph::Graph(std::uint64_t id, std::string label, std::string name) : id_(id), label_(label), name_(name), node_(nullptr), nodeCapacity_(0), nodeQuantity_(0) {}

const std::uint64_t &Graph::id() const { return id_; }
const std::string &Graph::label() const { return label_; }
const std::string &Graph::name() const { return name_; }

void Graph::setLabel(std::string label) { label_ = label; }
void Graph::setName(std::string name) { name_ = name; }

void Graph::addNode(Node* newNode){
    if(!newNode) return;
    if(!node_) instantiateGraph();
    if(nodeQuantity_ >= nodeCapacity_) increaseGraphCapacity();
    node_[nodeQuantity_] = newNode;
    nodeQuantity_++;
}

const Node *Graph::getNodeByID(std::uint64_t id){
    std::uint64_t index = findNodeIndexByID(id);
    return  index < nodeQuantity_ ? node_[index] : nullptr;
}

Node* Graph::removeNodeByID(std::uint64_t id){
    std::uint64_t index = findNodeIndexByID(id);
    if (index == nodeQuantity_) return nullptr;

    nodeQuantity_--;
    
    Node* removedNodePtr = node_[index];

    node_[index] = node_[nodeQuantity_];
    node_[nodeQuantity_] = nullptr;

    return removedNodePtr;
}

void Graph::instantiateGraph(){
    nodeCapacity_ = 10;
    nodeQuantity_ = 0;
    node_ = new Node*[nodeCapacity_];
}

void Graph::increaseGraphCapacity(){
    nodeCapacity_ *= 2;
    Node **newGraph = new Node*[nodeCapacity_];

    for(std::uint64_t i = 0; i < nodeQuantity_; i++) newGraph[i] = node_[i];

    delete[] node_;

    node_ = newGraph;
}

const std::uint64_t Graph::findNodeIndexByID(std::uint64_t id){
    std::uint64_t index = 0;
    while (index < nodeQuantity_ && node_[index]->id() != id) index++;
    return index;
}
