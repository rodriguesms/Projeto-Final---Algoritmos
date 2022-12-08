#ifndef GREEDY_H
#define GREEDY_H

#include "gift_stock.h"

class Greedy {
  public:
    unsigned int min_sleds;
    GiftStock data;
    
    Greedy(GiftStock instance);
    Greedy();
    void printSolution();
};

#endif