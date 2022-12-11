#include "../interfaces/utils.h"

Utils::Utils(){ 
  this->optimalSolutions={};
}

Utils::Utils(const char* path){

  std::fstream file;
  std::vector<std::string> solutionLines;

  file.open(path, std::ios::in);

  try{
    if(!file.is_open())
      throw "Solution file could not be opened!\n";
    for(std::string line; getline(file, line);){
      solutionLines.push_back(line);
    }
  }catch(const char *error){
    std::cout << error;
  }

  file.close();

  std::string delimiter=" = ";

  for(unsigned int line = 1; line < solutionLines.size(); line++){
    optimalSolutions.push_back(
      OptimalSolution{
        .instanceName = solutionLines[line].substr(0, solutionLines[line].find(delimiter)),
        .optimalValue = stoi(solutionLines[line].substr(solutionLines[line].find(delimiter)+delimiter.size(), solutionLines[line].size()))
      }
    );
  }
}

unsigned int Utils::getSolution(std::string &instanceName){
  auto iterator = std::find_if(optimalSolutions.begin(), optimalSolutions.end(),
    [instanceName](const OptimalSolution &solution){ return solution.instanceName == instanceName; });

  if(iterator != optimalSolutions.end()){
    auto index = std::distance(optimalSolutions.begin(), iterator);
    return optimalSolutions[index].optimalValue;
  }
  return 0;
}

