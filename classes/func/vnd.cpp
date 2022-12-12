#include "../interfaces/vnd.h"

Vnd::Vnd(){ }

Vnd::Vnd(Instance &instance, unsigned int &optimal){
  Greedy greedy = Greedy(instance);
  //greedy.printSolution(instance.instanceName, optimal);
  if(greedy.min_sleds.size() > optimal){
    // std::cout << "Greedy solution: " << greedy.min_sleds.size() << std::endl;
    // std::cout << "Optimal solution: " << optimal << std::endl;
    // std::cout << "Optimal solution doesn't find, trying neighborhood moves"<< std::endl;

    Swaps swap = Swaps(instance);
    // std::cout << "Find " << swap.solutionsSwap.size() << " swap possibilities" << std::endl;
    //swap.printSolutionSwaps();/
    unsigned int random_choice = rand() % swap.solutionsSwap.size();
    //std::cout << random_choice << std::endl;
    Redistribute redistribute = Redistribute(swap.solutionsSwap[random_choice], instance);
      unsigned int solution = 100000;
      unsigned int qtd_solution = 0;
      if(redistribute.solutions.size() > 0){
        qtd_solution = redistribute.solutions.size();
        //std::cout << "Find " << redistribute.solutions.size() << " solutions" << std::endl;
        for(unsigned int i = 0; i <  redistribute.solutions.size(); i++){
          if(redistribute.solutions[i].size() == optimal){
            // std::cout << "Redistribute find a optimal solution" << std::endl;
            qtd_solution = optimal;
            break; //já que é ótima, pego a primeira
          }else if(redistribute.solutions[i].size() < greedy.min_sleds.size()){
            solution > redistribute.solutions[i].size() ? solution = redistribute.solutions[i].size() : solution = solution;
            // std::cout << "Find " << redistribute.solutions.size() << " solutions using " << redistribute.solutions[i].size() << " sleds" <<std::endl;
          }    
        }
      }else{
        // std::cout << "Redistribute dont find a better solution" << std::endl;
      }
      if(qtd_solution > 0 && qtd_solution != optimal){
        // std::cout << "Find " << qtd_solution << " solutions using " << solution << " sleds" <<std::endl;
      }
  }else{
    // std::cout << "Greedy solution: " << greedy.min_sleds.size() << std::endl;
    // std::cout << "Optimal solution: " << optimal << std::endl;
    // std::cout << "Optimal solution found by greedy algorithm" << std::endl; 
  }
} 

void Vnd::printSolution(){
  std::cout << "\nSOLUTIONS\n" << std::endl;
  if(solutions.size() == 0){
    std::cout << "The algorithm did not find a better solution" << std::endl;
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