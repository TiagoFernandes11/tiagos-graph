#include <iostream>

#include "relation.hpp"
#include "node.hpp"

int main() {
    Node *pai = new Node(1, "Pessoa", "Pai");
    Node *filho = new Node(2, "Pessoa", "Filho");

    Relation *relation = new Relation(1, "Parentesco", "Pai", pai, filho);

    std::cout << "Relação " << relation->name() << " 1 " << relation->label() << " do tipo " << relation->name() 
        << " entre " << relation->nodes().first->name() << " e " << relation->nodes().second->name() << std::endl;

    pai->setName("Tiago");
    filho->setName("Sara");

    std::cout << "Relação " << relation->name() << " 2 " << relation->label() << " do tipo " << relation->name() 
        << " entre " << relation->nodes().first->name() << " e " << relation->nodes().second->name() << std::endl;

    return 0;
}