#pragma once

#include <string>
#include <cstdint>
#include <node.hpp>
#include <relation.hpp>

class Graph
{
    private:
        const std::uint64_t id_;
        std::string label_;
        std::string name_;

        Node **node_;
        std::uint64_t nodeCapacity_;
        std::uint64_t nodeQuantity_;

        // Relation ** relation_;
        // int relationCapacity_;
        // int relationQuantity_;

        void instantiateGraph();
        void increaseGraphCapacity();

        const std::uint64_t findNodeIndexByID(std::uint64_t id);

    public:
        Graph(std::uint64_t id, std::string label, std::string name);

        const std::uint64_t &id() const;
        const std::string &label() const;
        const std::string &name() const;

        void setLabel(std::string newLabel);
        void setName(std::string newName);

        void addNode(Node* newNode);
        const Node* getNodeByID(std::uint64_t id);
        Node* removeNodeByID(std::uint64_t id);

        // void addRelation(Relation* newRelation);
};