#include "util.hpp"

using std::string; 

std::vector<std::string> splitLine(std::string line) {
  std::stringstream s_stream(line);
  std::vector<string> vect;  
  while(s_stream.good()) {
    std::string str; 
    std::getline(s_stream, str, ','); 
    trim(str); 
    vect.push_back(str); 
  }
  vect.erase(vect.begin()); 
  return vect; 
}

static void trim(std::string& str) {
  trimRight(str); 
  trimLeft(str);  
}
static void trimLeft(std::string& str) {
  str.erase(0, str.find_first_not_of(" "));
}
static void trimRight(std::string& str) {
  str.erase(str.find_last_not_of(" ") + 1);
}