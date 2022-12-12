#ifndef SWAPS_H
#define SWAPS_H

#include<vector>
#include "greedy.h"

class Swaps{
    public:

    std::vector<Sled> solutionCopy;//Greedy's solution copy
    std::vector<std::vector<Sled>> solutionsSwap;

    Swaps();
    Swaps(Instance &instance); 

    void printSolutionSwaps(); 
};

#endif 