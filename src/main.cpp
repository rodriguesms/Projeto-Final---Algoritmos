#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <chrono>

#include "../classes/interfaces/instance.h"
#include "../classes/interfaces/greedy.h"
#include "../classes/interfaces/utils.h"
#include "../classes/interfaces/redistribute.h"
#include "../classes/interfaces/vnd.h"

int main(){
  auto start = std::chrono::steady_clock::now();
  std::string instancesPath = "./data/instances";
  std::vector<Instance> instances;
  std::vector<Greedy> instance_greedy_results;
  Utils utils = Utils("./data/solutions.txt");

  unsigned int instance_aux_index = 0;

  for(const auto &entry : std::filesystem::directory_iterator(instancesPath)){
    instances.push_back(Instance(entry.path()));
    // instance_greedy_results.push_back(
    //   Greedy(instances[instance_aux_index])
    // );

    unsigned int optimal = utils.getSolution(instances[instance_aux_index].instanceName);

    Vnd vnd = Vnd(instances[instance_aux_index], optimal);

    // instance_greedy_results[instance_aux_index].printSolution(instances[instance_aux_index].instanceName, optimal);
    // unsigned int greedyOptimalValue = instance_greedy_results[instance_aux_index].min_sleds.size();
    instance_aux_index++;
  }

//instance_greedy_results.size()
  // for(unsigned int i = 0; i < 1; i++){
  //   Vnd vnd = Vnd(instances[i], );
  //   // for(unsigned int j = 0; j < instance_greedy_results[i].min_sleds.size(); j++){
  //   //   std::cout << instance_greedy_results[i].min_sleds[j].allocated_gifts.size() << std::endl;
  //   // }
  //   // std::cout << i << std::endl;
  //   //std::cout << instances[i].sleds[i].allocated_gifts << std::endl;
  //   // Redistribute test = Redistribute(instances[i]);
  //   // test.printSolution();
  // }

  auto end = std::chrono::steady_clock::now();
  std::cout << "Time taken: " << std::chrono::duration<double,std::milli>(end-start).count() << "ms" << std::endl;
  return 0;
}