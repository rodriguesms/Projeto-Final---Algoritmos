#ifndef GIFT_STOCK_H
#define GIFT_STOCK_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "restrictions.h"

class GiftStock {
  public:
    unsigned int gift_quant;
    unsigned int sled_quant;
    unsigned int max_weight;
    unsigned int restriction_quant;
    std::vector<int> gift_weights;
    Restrictions restrictions;
    
    GiftStock(const char*);
    GiftStock();
    void printProblemInstance();

};

#endif