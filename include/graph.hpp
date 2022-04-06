#pragma once

#include "node.hpp"

using std::vector; 
using std::string; 

class Graph {
public:
  Graph() = default; 
  ~Graph(); 

  void addNode(Node* node); 
  void addNode(string s); 
private:
  vector<Node*> nodes;
}; 