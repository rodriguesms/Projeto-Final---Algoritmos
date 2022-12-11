#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "restrictions.h"
#include "gift.h"
#include "sled.h"

class Instance {
  public:
    unsigned int max_weight;
    std::vector<Gift> gifts;
    std::vector<Sled> sleds;
    Restrictions restrictions;
    
    Instance(const char*);
    Instance();
    void printProblemInstance();
    void printSleds();
};

#endif