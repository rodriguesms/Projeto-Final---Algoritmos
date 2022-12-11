#ifndef VND_H
#define VND_H

#include "instance.h"
#include "greedy.h"
#include <vector>
#include <algorithm>
#include "sled.h"
#include "utils.h"
#include "redistribute.h"


class Vnd {
  public:
    std::vector<Sled> min_sleds;
    std::vector<std::vector<Sled>> solutions;
    std::vector<Gift> removed_gifts;

    Vnd(Instance &instance, unsigned int &optimal);
    Vnd();
    void printSolution();
};

#endif