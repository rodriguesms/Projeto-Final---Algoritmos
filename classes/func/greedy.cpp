#include "../interfaces/greedy.h"

Greedy::Greedy(){ }

Greedy::Greedy(Instance &instance) {
 
  /*
  * Order Gifts by the Greedy Choice: Heavier gifts
  */
  std::sort(instance.gifts.begin(), instance.gifts.end(),
    [](const Gift& giftL, const Gift& giftR){
      return giftL.weight > giftR.weight;
    });
  
  for(Gift gift : instance.gifts){
    for(unsigned int i = 0; i < instance.sleds.size(); i++){
      bool next_sled = false;
      // std::cout << "\nGift " << gift.id << " | Sled: " << instance.sleds[i].id << std::endl;
      // Check if the present gift fits in this sled
      if(instance.sleds[i].getWeight()+gift.weight <= instance.max_weight){
        // std::cout << "Fitted (Gift weight: " << gift.weight << " Kg | Free capacity in sled: " 
        //   << instance.max_weight-instance.sleds[i].getWeight() << " Kg)" << std::endl;
        // Check if there is a restriction between a gift allocated to this sled and the present gift
        for(Gift allocated_gift : instance.sleds[i].allocated_gifts){
          if(instance.restrictions.isNeighbour(gift.id, allocated_gift.id)){
            // std::cout << "The gift " << gift.id << " has a restriction to the gift " << allocated_gift.id 
            //   << ", skipping this sled" << std::endl;
            // If there is a restriction, go to the next sled
            next_sled = true;
            break;
          }
        }
        if(!next_sled){ // Check if this gift can be allocated to this sled
          // std::cout << "Fitted and didn't have any restriction,  allocating gift " <<
          // gift.id << " to sled " << instance.sleds[i].id << " and moving foward to the next gift" << std::endl;
          instance.sleds[i].addGift(gift);
          // If this sled is not in the min_sled solution, push it back
          if(!checkSledSolutionPresence(instance.sleds[i]))
            min_sleds.push_back(instance.sleds[i]);
          else
            min_sleds[i] = instance.sleds[i];
          break; // Go to the next gift
        }
      }else{
        // std::cout << "Didn't fit (Gift weight: " << gift.weight << " Kg | Free capacity in sled: " 
        //   << instance.max_weight-instance.sleds[i].getWeight() << " Kg)" << std::endl;
      }
      continue; // Go to the next sled
    }
  }
}

bool Greedy::checkSledSolutionPresence(Sled &sled){
  for(Sled sled_iter:min_sleds){
    if(sled_iter.id == sled.id)
      return true;
  }
  return false;
}

void Greedy::printSolution(std::string &instanceName, unsigned int &optimalSolution){
  std::cout << "\nGreedy solution (" << instanceName << "):" << std::endl;
  std::cout << "Optimal solution: " << optimalSolution << std::endl;
  std::cout << "Minimum sled quantity: " << min_sleds.size() << std::endl;
  for(unsigned int i = 0; i < min_sleds.size(); i++){
    std::cout << "Sled " << min_sleds[i].id << " ("<< min_sleds[i].allocated_gifts.size()<<" gifts): [ ";
    for(unsigned int j = 0; j < min_sleds[i].allocated_gifts.size(); j++){
      std::cout << min_sleds[i].allocated_gifts[j].id << " ";
    }
    std::cout << "] (Weight: " << min_sleds[i].getWeight() << " Kg)" << std::endl;
  }
}