#include "processdata.hpp"
#include <iostream>
//#include <matrix.hpp>


int main() {

  Graph graph = buildGraph("data/fixed_data.csv"); 
  std::unordered_map<std::string, Node*> mp = graph.getNodes(); 
  std::cout << mp.size() << std::endl; 
}