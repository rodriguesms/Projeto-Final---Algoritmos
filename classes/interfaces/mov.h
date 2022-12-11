#ifndef MOV_H
#define MOV_H

#include "instance.h"
#include <vector>
#include <algorithm>
#include "sled.h"

class Mov {
  public:
    std::vector<Sled> min_sleds;
    std::vector<std::vector<Sled>> solutions;
    std::vector<Gift> removed_gifts;

    Mov(Instance &instance);
    Mov();
    void printSolution();
};

#endif