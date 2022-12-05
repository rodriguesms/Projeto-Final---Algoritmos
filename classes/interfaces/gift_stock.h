#ifndef GIFT_STOCK_H
#define GIFT_STOCK_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class GiftStock {
  public:
    int gift_quant;
    int sled_quant;
    int max_weight;
    int restriction_quant;
    std::vector<int> gift_weights;
    std::vector<std::vector<int>> restrictions;
    
    GiftStock(const char*);
    GiftStock();
    void printProblemInstance();

};

#endif