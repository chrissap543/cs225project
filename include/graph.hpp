#pragma once

#include "node.cpp"

using std::vector; 

class Graph {
public:
  Graph(); 
  ~Graph(); 
private:
  vector<Node*> nodes; 
}; 