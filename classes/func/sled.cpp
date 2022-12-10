#include "../interfaces/sled.h"

Sled::Sled(){
  id = -1;
  allocated_gifts = {};
}
Sled::Sled(unsigned int &id){
  this->id = id;
  this->allocated_gifts = {};
}

void Sled::addGift(Gift &gift){
  allocated_gifts.push_back(gift);
}

void Sled::printGifts(){
  for(Gift gift : allocated_gifts){
    std::cout << gift.id << std::endl;
  }
}

unsigned int Sled::getWeight(){
  unsigned int weight = 0;
  for(Gift gift : allocated_gifts){
    weight+=gift.weight;
  }
  return weight;
}