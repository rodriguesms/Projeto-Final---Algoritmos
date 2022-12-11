#include <iostream>
#include "../classes/interfaces/instance.h"
#include "../classes/interfaces/greedy.h"
#include "../classes/interfaces/redistribute.h"


int main(){

  Instance instance = Instance("./data/instances/n30_k150_A.txt");
  instance.printProblemInstance();

  Greedy greedy = Greedy(instance);
  greedy.printSolution();
  //instance.printSleds();

  Redistribute mov = Redistribute(instance);
  mov.printSolution();

  return 0;
}