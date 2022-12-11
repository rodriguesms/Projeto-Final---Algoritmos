#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include "restrictions.h"
#include "gift.h"
#include "sled.h"

class Instance {
  public:
    std::string instanceName;
    unsigned int max_weight;
    std::vector<Gift> gifts;
    std::vector<Sled> sleds;
    Restrictions restrictions;
    
    Instance(std::filesystem::path);
    Instance();
    void printProblemInstance();

};

#endif