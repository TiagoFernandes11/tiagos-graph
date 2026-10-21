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

        Node **node;
        int nodeCapacity;
        int nodeQuantity;

        Relation ** relation;
        int relationCapacity;
        int relationQuantity;

    public:
        Graph(std::uint64_t id, std::string label, std::string name);

        const std::uint64_t &id() const;
        const std::string &label() const;
        const std::string &name() const;

        void setLabel(std::string newLabel);
        void setName(std::string newName);

        void addNode(Node* newNode);
        void addRelation(Relation* newRelation);
};