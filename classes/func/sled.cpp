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

void Sled::swapGifts(Gift &gift1, Gift &gift2){
  Gift temp = Gift();

  temp = gift1;
  gift1 = gift2;
  gift2 = temp;
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