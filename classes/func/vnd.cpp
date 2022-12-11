#include "../interfaces/vnd.h"

Vnd::Vnd(){ }

Vnd::Vnd(Instance &instance, unsigned int &optimal){
  unsigned int move = 0;
  Greedy greedy = Greedy(instance);
  //greedy.printSolution(instance.instanceName, optimal);
  if(greedy.min_sleds.size() > optimal){
    std::cout << "\n\nGreedy solution: " << greedy.min_sleds.size() << std::endl;
    std::cout << "Optimal solution: " << optimal << std::endl;
    std::cout << "Optimal solution wasn't found, trying neighborhood moves"<< std::endl;
    switch(move){
      case 0:
        move++;
      case 1:
        std::cout << "Trying optimization with redistribution" << std::endl;
        Redistribute redistribute = Redistribute(instance);
        if(redistribute.solutions.size() > 0){
          std::cout << "Find " << redistribute.solutions.size() << " solutions" << std::endl;
          for(unsigned int i = 0; i <  redistribute.solutions.size(); i++){
            if(redistribute.solutions[i].size() == optimal){
              std::cout << "Redistribution found an optimal solution" << std::endl;
              break; //já que é ótima, pego a primeira
            }
            if(redistribute.solutions[i].size() < greedy.min_sleds.size()){
              std::cout << "Found a solution using " << redistribute.solutions[i].size() << " sleds" << std::endl;
            }    
          }
        }else{
          std::cout << "Redistribution didn't found a better solution" << std::endl;
        }
        
    }
  }else{
    std::cout << "Greedy solution: " << greedy.min_sleds.size() << std::endl;
    std::cout << "Optimal solution: " << optimal << std::endl;
    std::cout << "Optimal solution found by greedy algorithm" << std::endl; 

  }
} 

void Vnd::printSolution(){
  std::cout << "\nSOLUTIONS\n" << std::endl;
  if(solutions.size() == 0){
    std::cout << "The algorithm did not found a better solution" << std::endl;
  }else{
    for(unsigned int i = 0; i < solutions.size(); i++){
      std::cout << "\nSOLUTION " << i+1 << std::endl;
      std::cout << "Minimum sled quantity: " << solutions[i].size() << std::endl;
      for(unsigned int j = 0; j < solutions[i].size(); j++){
        std::cout << "Sled " << j+1 << " ("<< solutions[i][j].allocated_gifts.size()<<" gifts): [ ";
        for(unsigned int k = 0; k < solutions[i][j].allocated_gifts.size(); k++){
        std::cout << solutions[i][j].allocated_gifts[k].id << " ";
      }
      std::cout << "] (Weight: " << solutions[i][j].getWeight() << " Kg)" << std::endl;
      }
    }
  }
}