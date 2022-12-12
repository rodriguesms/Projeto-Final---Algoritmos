#include "../interfaces/swaps.h"

Swaps::Swaps(){};

Swaps::Swaps(Instance &instance){
    Instance solutionCopy = instance;
    int test = 0;
    bool conflitc = false;

    for(unsigned int i = 0; i < solutionCopy.sleds.size(); i++){//Get the first sled to make the swap
        for(unsigned int j = 0; j < solutionCopy.sleds[i].allocated_gifts.size(); j++){//Get the first gift to make the swap
            for(unsigned int k = 0; k < solutionCopy.sleds.size(); k++){//Go through the sled vector to make the swap
              for(unsigned int l = 0; l < solutionCopy.sleds[k].allocated_gifts.size(); l++){//Getting a swap's candidate
                
                //Weight's restriction 1 - Verifying the weight before doing the Swap of the destination's sled 
                if(solutionCopy.sleds[k].getWeight() - solutionCopy.sleds[k].allocated_gifts[l].weight + solutionCopy.sleds[i].allocated_gifts[j].weight > instance.max_weight){
                  //std::cout << "/* Erro de peso no destino */" << std::endl;
                  continue; 
                }
                //Weight's restriction 2 - Verifying the weight before doing the Swap of the source's sled
                if(solutionCopy.sleds[i].getWeight() + solutionCopy.sleds[k].allocated_gifts[l].weight - solutionCopy.sleds[i].allocated_gifts[j].weight > instance.max_weight){
                  //std::cout << "/* Erro de peso na origem */" << std::endl;
                  continue; 
                }
                //Conflict's restriction - Verifying the gifts conflictions of the destinations's sled            
                for(unsigned int c = 0; c < solutionCopy.sleds[k].allocated_gifts.size(); c++){
                  if(instance.restrictions.isNeighbour(solutionCopy.sleds[i].allocated_gifts[j].id, solutionCopy.sleds[k].allocated_gifts[c].id)
                     && solutionCopy.sleds[k].allocated_gifts[l].id != solutionCopy.sleds[k].allocated_gifts[c].id){
                    
                    //std::cout << "/* Erro de conflito no destino */" << std::endl;
                    //std::cout << "Presente: " << solutionCopy.sleds[i].allocated_gifts[j].id << " e " << "Presente: " << solutionCopy.sleds[k].allocated_gifts[c].id << std::endl;
                    
                    conflitc = true;
                    continue;
                  }
                }              
                if(conflitc){
                  conflitc = 0;
                  continue;
                }
                //Conflict's restriction - Verifying the gifts conflictions of the source's sled            
                for(unsigned int b = 0; b < solutionCopy.sleds[i].allocated_gifts.size(); b++){
                  if(instance.restrictions.isNeighbour(solutionCopy.sleds[k].allocated_gifts[l].id, solutionCopy.sleds[i].allocated_gifts[b].id)
                     && solutionCopy.sleds[i].allocated_gifts[j].id != solutionCopy.sleds[i].allocated_gifts[b].id){
                    
                    //std::cout << "/* Erro de conflito na origem */" << std::endl;
                    //std::cout << "Presente: " << solutionCopy.sleds[k].allocated_gifts[l].id << " e " << "Presente: " << solutionCopy.sleds[i].allocated_gifts[b].id << std::endl;
                    
                    conflitc = true;
                    continue;
                  }
                }               
                if(conflitc){
                  conflitc = 0;
                  continue;
                }
                //Secure Swap
                solutionCopy.sleds[i].swapGifts(solutionCopy.sleds[i].allocated_gifts[j], solutionCopy.sleds[k].allocated_gifts[l]);                 

                /*std::cout << "\nSOLUTION: " << std::endl;
                std::cout << "Minimum sled quantity: " << solutionCopy.size() << std::endl;
                  for(unsigned int p = 0; p < solutionCopy.size(); p++){
                    std::cout << "Sled " << solutionCopy[p].id << " ("<< solutionCopy[p].allocated_gifts.size()<<" gifts): [ ";
                    for(unsigned int o = 0; o < solutionCopy[p].allocated_gifts.size(); o++){
                      std::cout << solutionCopy[p].allocated_gifts[o].id << " ";
                    }
                    std::cout << "] (Weight: " << solutionCopy[p].getWeight() << " Kg)" << std::endl;
                  }*/
                solutionsSwap.push_back(solutionCopy.sleds);    

                //Re-Swap to get all possibility with this gift, maintain the orginal vector.
                solutionCopy.sleds[i].swapGifts(solutionCopy.sleds[k].allocated_gifts[l], solutionCopy.sleds[i].allocated_gifts[j]);
              
                test++;
                // if(test == 30){
                //   system("pause");
                // }
              }
            }
        }
    }

}

/*
    std::cout << "\nSOLUTION: " << k << std::endl;
    std::cout << "Minimum sled quantity: " << solutionCopy.size() << std::endl;
    for(unsigned int i = 0; i < solutionCopy.size(); i++){
      std::cout << "Sled " << solutionCopy[i].id << " ("<< solutionCopy[i].allocated_gifts.size()<<" gifts): [ ";
      for(unsigned int j = 0; j < solutionCopy[i].allocated_gifts.size(); j++){
        std::cout << solutionCopy[i].allocated_gifts[j].id << " ";
      }
      std::cout << "] (Weight: " << solutionCopy[i].getWeight() << " Kg)" << std::endl;
    }
*/

void Swaps::printSolutionSwaps(){
  
  std::cout << "Swaps Solution\n" << std::endl;
  std::cout << solutionsSwap.size() << std::endl;

  // for(unsigned int i = 0; i < solutionsSwap.size(); i++){
  //   std::cout << "\nSOLUTION: " << i+1 << std::endl;
  //   std::cout << "Minimum sled quantity: " << solutionsSwap[i].size() << std::endl;
  //   for(unsigned int j = 0; j < solutionsSwap[i].size(); j++){
  //     std::cout << "Sled " << solutionsSwap[i][j].id << " ("<< solutionsSwap[i][j].allocated_gifts.size()<<" gifts): [ ";
  //     for(unsigned int k = 0; k < solutionsSwap[i][j].allocated_gifts.size(); k++){
  //       std::cout << solutionsSwap[i][j].allocated_gifts[k].id << " ";
  //     }
  //     std::cout << "] (Weight: " << solutionsSwap[i][j].getWeight() << " Kg)" << std::endl;
  //   }
  // }  
}