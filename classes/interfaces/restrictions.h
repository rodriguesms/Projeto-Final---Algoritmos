#ifndef RESTRICTIONS_H
#define RESTRICTIONS_H

#include <vector>

class Restrictions {

  public:
    int nodes;
    std::vector<int> *adjacency;

    Restrictions();
    Restrictions(unsigned int &nodes);
    void addEdge(unsigned int &node1, unsigned int &node2);
    bool isNeighbour(unsigned int &node1, unsigned int &node2);
    void printAdjacency();
};

#endif