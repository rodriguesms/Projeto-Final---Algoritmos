#ifndef GIFT_H
#define GIFT_H

class Gift {
  public:
    unsigned int id;
    unsigned int weight;
    
    Gift();
    Gift(unsigned int &id, unsigned int &weight);
};

#endif