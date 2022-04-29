#include "graph.hpp"
#include "node.hpp"
#include "matrix.hpp"
#include "processdata.hpp"

#include <iostream>
#include <string>

int main() {
  Graph g = buildGraph("../data/fixed_data.csv"); 
  auto vect = g.highestDegree(); 
  for(auto str : vect)
    std::cout << str << std::endl; 
}