#include "../interfaces/instance.h"

using namespace std;

std::vector<unsigned int> getVectorNumberFromString(string str){
  stringstream string_stream;
  std::vector<unsigned int> array;
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

Instance::Instance(){
  this->max_weight=0;
  this->restrictions = {};
  this->instanceName = "";
}

Instance::Instance(filesystem::path path){

  this->instanceName = path.filename().string()
    .substr(0, path.filename().string().find_last_of(".")); //removing extension

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

  unsigned int gift_quant = stoi(lines[1]);
  unsigned int sled_quant = stoi(lines[2]);
  this->max_weight = stoi(lines[3]);
  unsigned int restriction_quant = stoi(lines[4]);
  std::vector<unsigned int> gift_weights;

  std::stringstream bString(lines[6]);
  std::string bStringValue;

  while(getline(bString, bStringValue, ' ')){
    gift_weights.push_back(stoi(bStringValue));
  }

  for(unsigned int i = 0; i < gift_weights.size(); i++){
    unsigned int id = i+1;
    this->gifts.push_back(Gift(id, gift_weights[i]));
  }

  for(unsigned int j = 0; j < sled_quant; j++){
    unsigned int id = j+1;
    this->sleds.push_back(Sled(id));
  }

  this->restrictions = Restrictions(gift_quant);

  for(int i = 8; i < lines.size(); i++){
    std::vector<unsigned int> restriction = getVectorNumberFromString(lines[i]);
    restrictions.addEdge(restriction[0], restriction[1]);
  }
}

void Instance::printProblemInstance(){
  std::cout << "Gift quantity: " << this->gifts.size() << std::endl;
  std::cout << "Sled quantity: " << this->sleds.size() << std::endl;
  std::cout << "Max weight (Kg): " << this->max_weight << std::endl;
  std::cout << "Gift weights: [ ";

  for(Gift gift:gifts){
    std::cout << gift.weight << " ";
  }
  std::cout << " ]" << std::endl;

  restrictions.printAdjacency();
}