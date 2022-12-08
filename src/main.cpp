#include <iostream>
#include "../classes/interfaces/instance.h"

int main(){

  Instance instance = Instance("./data/instances/n30_k150_A.txt");
  instance.printProblemInstance();
  return 0;
}