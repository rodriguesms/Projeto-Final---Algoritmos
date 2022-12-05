#include "../interfaces/gift_stock.h"

using namespace std;

std::vector<int> getVectorNumberFromString(string str){
  stringstream string_stream;
  std::vector<int> array;
  string_stream << str;
  string aux_str;
  int aux_int;
  while(!string_stream.eof()){
    string_stream >> aux_str;
    if(stringstream(aux_str) >> aux_int){
      array.push_back(aux_int);
    }
    aux_str = "";
  }
  return array;
}

GiftStock::GiftStock(){
  this->gift_quant=0;
  this->sled_quant=0;
  this->max_weight=0;
  this->restriction_quant=0;
  this->gift_weights = {};
  this->restrictions = {};
}

GiftStock::GiftStock(const char *path){
  std::fstream file;
  std::vector<std::string> lines;

  file.open(path, std::ios::in);
  try{
    if(!file.is_open()){
      throw "File could not be opened!\n";
    }

    for(std::string line; getline(file, line);){
      lines.push_back(line);
    }
  }catch(const char *error){
    std::cout << error;
  }

  file.close();  

  gift_quant = stoi(lines[1]);
  sled_quant = stoi(lines[2]);
  max_weight = stoi(lines[3]);
  restriction_quant = stoi(lines[4]);

  std::stringstream bString(lines[6]);
  std::string bStringValue;

  while(getline(bString, bStringValue, ' ')){
    gift_weights.push_back(stoi(bStringValue));
  }

  for(int i = 8; i < lines.size(); i++){
    restrictions.push_back(getVectorNumberFromString(lines[i]));
  }
}

void GiftStock::printProblemInstance(){
  std::cout << "Gift quantity: " << gift_quant << std::endl;
  std::cout << "Sled quantity: " << sled_quant << std::endl;
  std::cout << "Max weight (Kg): " << max_weight << std::endl;
  std::cout << "Restriction quantity: " << restriction_quant << std::endl;
  std::cout << "Gift weights: [ ";

  for(int weight:gift_weights){
    std::cout << weight << " ";
  }
  std::cout << " ]" << std::endl;

  std::cout << restrictions[24][1] << std::endl;

  std::cout << "Restrictions: [ ";
  for(int i = 0; i < restriction_quant; i++){
    std::cout << "{ ";
    for(int j = 0; j < 2; j++){
      std::cout << restrictions[i][j] << " ";
    }
    std::cout << "} ";
  }
  std::cout << "]" << std::endl;
}