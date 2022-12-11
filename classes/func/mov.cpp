#include "../interfaces/mov.h"

Mov::Mov(){ }

Mov::Mov(Instance &instance){
  
    Instance copy_instance = instance; 
    unsigned int add = 0;
    unsigned int removed = 0;

    for(unsigned int i = 0; i < instance.sleds.size(); i++){
      //Esvazia o trenó e adciona os presentes numa lista
      for( Gift gift : copy_instance.sleds[i].allocated_gifts){
        removed_gifts.push_back(gift);
      }
      //limpa o trenó
      copy_instance.sleds[i].allocated_gifts.clear();
      //Tenta colocar presentes em outro carrinho
      //itera sobre os presentes que foram retirados
      for(int j = removed_gifts.size()-1; j >= 0; j--){
        //para cada presente percorre toda instancia
        for(unsigned int k = 0; k < instance.sleds.size(); k++){
          bool can_be_added = true;
          //se o carrinho não estiver vazio, tenta adicionar o presente retirado nele
          if(copy_instance.sleds[k].getWeight() > 0){
            //se o peso do presente removido + o preso do trenó for menor que o máxio, entra aqui, se não avisa que não cabe em nenhum
            if(copy_instance.sleds[k].getWeight()+removed_gifts[j].weight <= instance.max_weight){
              //para cada presente dos presentes que já estão no trenó checa se tem restrição
              for(Gift gift : instance.sleds[k].allocated_gifts){
                //se tiver restriçao, seta a flag que não dá pra adicionar pra false
                if(instance.restrictions.isNeighbour(removed_gifts[j].id, gift.id)){
                  std::cout << "Gift " << removed_gifts[j].id << " has a restriction to the gift " << gift.id<< std::endl;
                  can_be_added = false;  
                }else{
                  std::cout << "Gift " << removed_gifts[j].id << " has no restrictions with the gift " << gift.id << std::endl;
                }
              }
            }else{
              std::cout << "The gift " << removed_gifts[j].id << " with " << removed_gifts[j].weight
              << "KG " << "don't fit in sled " << k << std::endl;  
              can_be_added = false;  
            }
            for(int f = 0; f < removed_gifts.size(); f++){
                  std::cout << "Gifts: "<< removed_gifts[f].id << std::endl;
                }
            //se puder adicionar o presente em algum canto, adiciona e incrementa um contador em seguida retira ele da lista, independente de ter sido adicionado ou não
            if(can_be_added){
              std::cout << "Gift " << removed_gifts[j].id << " added to sled " << copy_instance.sleds[k].id << std::endl;
              copy_instance.sleds[k].addGift(removed_gifts[j]);
              removed_gifts.pop_back();
              add++;
              removed++;
              break;
            }
          }
        }
      }
      while(removed_gifts.size() > 0){
        removed_gifts.pop_back();
        removed++;
      }
      std::cout << add <<" "<< removed << std::endl;
      //se o numero de presentes adicionados em outros trenós for igual ao de retirados do trenó da iteração, imprime um aviso
      if(add == removed && instance.sleds[i].getWeight() > 0){
        std::cout << "All gifts from sled " << i+1 << " were redistributed" << std::endl;
        for(unsigned int x = 0; x < instance.sleds.size(); x++){
          if(copy_instance.sleds[x].allocated_gifts.size() > 0){
            min_sleds.push_back(copy_instance.sleds[x]);
          }
          std::cout << "[ ";
          for(unsigned int y = 0; y < copy_instance.sleds[x].allocated_gifts.size(); y++){
              std::cout << copy_instance.sleds[x].allocated_gifts[y].id << " ";
          }
          std::cout << "]" <<std::endl;
        }
      }else{
        std::cout << "All gifts from sled " << i+1 << " were not redistributed" << std::endl;
      }

      add = 0;
      removed = 0;

      copy_instance = instance;   
      std::cout << i << std::endl;   
    }
      std::cout << "sai?" << std::endl;
    //  for(unsigned int i = 0; i < instance.sleds.size(); i++){
    //    std::cout << "[ ";
    //     for(unsigned int j = 0; j < instance.sleds[i].allocated_gifts.size(); j++){
    //         std::cout << instance.sleds[i].allocated_gifts[j].id << " ";
    //     }
    //     std::cout << "]" <<std::endl;

    //     std::cout << "[ ";
    //     for(unsigned int j = 0; j < copy_instance.sleds[i].allocated_gifts.size(); j++){
    //         std::cout << copy_instance.sleds[i].allocated_gifts[j].id << " ";
    //     }
    //     std::cout << "]" <<std::endl;
    //  }

}

void Mov::printSolution(){
  std::cout << "\nSOLUTION: " << std::endl;
  std::cout << "Minimum sled quantity: " << min_sleds.size() << std::endl;
  for(unsigned int i = 0; i < min_sleds.size(); i++){
    std::cout << "Sled " << min_sleds[i].id << " ("<< min_sleds[i].allocated_gifts.size()<<" gifts): [ ";
    for(unsigned int j = 0; j < min_sleds[i].allocated_gifts.size(); j++){
      std::cout << min_sleds[i].allocated_gifts[j].id << " ";
    }
    std::cout << "] (Weight: " << min_sleds[i].getWeight() << " Kg)" << std::endl;
  }
}