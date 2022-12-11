#ifndef SWAPS_H
#define SWAPS_H

#include<vector>
#include "greedy.h"

class Swaps{
    public:

    std::vector<Sled> solutionCopy;//Greedy's solution copy
    std::vector<std::vector<Sled>> solutionsSwap;

    Swaps();
    Swaps(Greedy &greddySolution, Instance &instance); 

    void printSolutionSwaps(); 
};

#endif 