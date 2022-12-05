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
      std::cout << line << std::endl;
    }
  }catch(const char *error){
    std::cout << error;
  }

  file.close();  
}