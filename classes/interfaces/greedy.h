#ifndef GREEDY_H
#define GREEDY_H

#include "instance.h"

class Greedy {
  public:
    unsigned int min_sleds;
    Instance data;
    
    Greedy(Instance instance);
    Greedy();
    void printSolution();
};

#endif