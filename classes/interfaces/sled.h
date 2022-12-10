#ifndef SLED_H
#define SLED_H

#include "gift.h"
#include <iostream>
#include <vector>

class Sled {

  public:
    unsigned int id;
    std::vector<Gift> allocated_gifts;


    Sled();
    Sled(unsigned int &id);
    void addGift(Gift &gift);
    void printGifts();
    unsigned int getWeight();
};

#endif