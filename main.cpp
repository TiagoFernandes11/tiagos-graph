#include <iostream>

#include "relation.hpp"
#include "node.hpp"
#include "graph.hpp"

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

    // Testes do Graph
    Graph *graph = new Graph(1, "Familia", "Familia Fernandes");

    std::cout << "Grafo " << graph->id() << " " << graph->name() << " do tipo " << graph->label() << std::endl;

    graph->setName("Familia Silva");
    graph->setLabel("Arvore");

    std::cout << "Grafo " << graph->id() << " " << graph->name() << " do tipo " << graph->label() << std::endl;

    graph->addNode(pai);
    graph->addNode(filho);
    std::cout << "Adicionou os nós " << pai->name() << " e " << filho->name() << std::endl;

    graph->addNode(nullptr);
    std::cout << "Adicionar nullptr não quebrou" << std::endl;

    for (int i = 3; i <= 15; i++) {
        graph->addNode(new Node(i, "Pessoa", "Pessoa " + std::to_string(i)));
    }
    std::cout << "Adicionou mais 13 nós (total 15) sem quebrar" << std::endl;

    return 0;
}