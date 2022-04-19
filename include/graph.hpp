#pragma once

#include "node.hpp"

#include <unordered_map>

using std::string; 
using std::unordered_map; 

class Graph {
public:
  Graph(unordered_map<string, Node*> nodes_); 
  ~Graph(); 

  const unordered_map<string, Node*>& getNodes() const; 

  void dfs(); 
  void dfs(Node* start); 
private:
  unordered_map<string, Node*> nodes; 

  const int NUM_DATA_POINTS = 55863; // gotten from Stanford SNAP
}; 