#include <iostream>
#include "../classes/interfaces/gift_stock.h"

int main(){

  GiftStock giftStock = GiftStock("./data/instances/n30_k150_A.txt");
  giftStock.printProblemInstance();
  return 0;
}