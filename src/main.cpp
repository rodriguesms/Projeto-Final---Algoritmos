#include <iostream>
#include "../classes/interfaces/instance.h"
#include "../classes/interfaces/greedy.h"
#include "../classes/interfaces/mov.h"


int main(){

  Instance instance = Instance("./data/instances/n120_k150_B.txt");
  instance.printProblemInstance();

  Greedy greedy = Greedy(instance);
  greedy.printSolution();
  //instance.printSleds();

  Mov mov = Mov(instance);
  mov.printSolution();

  return 0;
}