#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "restrictions.h"

class Instance {
  public:
    unsigned int gift_quant;
    unsigned int sled_quant;
    unsigned int max_weight;
    unsigned int restriction_quant;
    std::vector<int> gift_weights;
    Restrictions restrictions;
    
    Instance(const char*);
    Instance();
    void printProblemInstance();

};

#endif