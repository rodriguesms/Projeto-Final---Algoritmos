#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "../classes/interfaces/instance.h"
#include "../classes/interfaces/greedy.h"
#include "../classes/interfaces/utils.h"

int main(){

  std::string instancesPath = "./data/instances";
  std::vector<Instance> instances;
  std::vector<Greedy> instance_greedy_results;
  Utils utils = Utils("./data/solutions.txt");

  unsigned int instance_aux_index = 0;

  for(const auto &entry : std::filesystem::directory_iterator(instancesPath)){
    instances.push_back(Instance(entry.path()));
    instance_greedy_results.push_back(
      Greedy(instances[instance_aux_index])
    );

    unsigned int optimal = utils.getSolution(instances[instance_aux_index].instanceName);

    instance_greedy_results[instance_aux_index].printSolution(instances[instance_aux_index].instanceName, optimal);
    unsigned int greedyOptimalValue = instance_greedy_results[instance_aux_index].min_sleds.size();
    instance_aux_index++;
  }

  return 0;
}