#ifndef REDISTRIBUTE_H
#define REDISTRIBUTE_H

#include "instance.h"
#include <vector>
#include <algorithm>
#include "sled.h"

class Redistribute {
  public:
    std::vector<Sled> min_sleds;
    std::vector<std::vector<Sled>> solutions;
    std::vector<Gift> removed_gifts;

    Redistribute(Instance &instance);
    Redistribute();
    void printSolution();
};

#endif