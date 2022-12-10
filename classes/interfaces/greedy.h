#ifndef GREEDY_H
#define GREEDY_H

#include "instance.h"
#include <vector>
#include <algorithm>
#include "sled.h"

struct GreedyChoice {
  unsigned int giftId;
  float greedyChoiceValue;
};

class Greedy {
  public:
    std::vector<Sled> min_sleds;
    
    Greedy(Instance &instance);
    Greedy();
    void printSolution();
    bool checkSledSolutionPresence(Sled &sled);
};

#endif