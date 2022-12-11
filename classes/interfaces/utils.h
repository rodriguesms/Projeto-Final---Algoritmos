#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include "instance.h"

struct OptimalSolution {
  std::string instanceName;
  int optimalValue;
};

class Utils {

  public:
    std::vector<OptimalSolution> optimalSolutions;
    
    unsigned int getSolution(std::string &instanceName);
    Utils();
    Utils(const char* path);
    //void printSolutionGap(std::string &instanceName);
  
};

#endif // !UTIL_H