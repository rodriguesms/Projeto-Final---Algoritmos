#include "../interfaces/restrictions.h"
#include <iostream>

Restrictions::Restrictions(){
  this->nodes=0;
  this->adjacency=NULL;
}

Restrictions::Restrictions(unsigned int &nodes){
  this->nodes=nodes;
  this->adjacency=new std::vector<int>[this->nodes];
}

void Restrictions::addEdge(unsigned int &node1, unsigned int &node2){
  this->adjacency[node1-1].push_back(node2-1);
  this->adjacency[node2-1].push_back(node1-1);
}

bool Restrictions::isNeighbour(unsigned int &node1, unsigned int &node2){

  unsigned int node1Neighbours = this->adjacency[node1-1].size();
  unsigned int node2Neighbours = this->adjacency[node2-1].size();

  if(node1Neighbours <= node2Neighbours){
    for(unsigned int i = 0; i < node1Neighbours; i++){
      if(this->adjacency[node1-1][i] == node2-1) return true; 
    }
    return false;
  }
  else{
    for(unsigned int i = 0; i < node2Neighbours; i++){
      if(this->adjacency[node2-1][i] == node1-1) return true; 
    }
    return false;
  }
}

void Restrictions::printAdjacency(){

  std::cout << "Restrictions: " << std::endl;
  for(unsigned int i = 0; i < this->nodes; i++){
    std::cout << "Gift " << i+1 << ":";
    unsigned int node_restrictions = this->adjacency[i].size();
    std::cout << "{ ";
    for(unsigned int j = 0; j < node_restrictions; j++){
      std::cout << this->adjacency[i][j]+1 << " ";
    }
    std::cout << "}" << std::endl;
  }

}
