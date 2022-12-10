#include "../interfaces/gift.h"

Gift::Gift(){
  id=-1;
  weight=0;
}

Gift::Gift(unsigned int &id, unsigned int &weight){
  this->id = id;
  this->weight = weight;
}