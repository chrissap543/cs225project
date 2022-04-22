#pragma once

#include "node.hpp"

#include <unordered_map>

using std::string; 
using std::unordered_map; 
#include <stack>
class Graph {
public:
  Graph(unordered_map<string, Node*> nodes_); 
  ~Graph(); 

  const unordered_map<string, Node*>& getNodes() const; 

  void dfs(); 

  /**
 * @brief 
 * @param file_name the name of a csv file
 * @return void
 */
  void dfs(Node* start); 
private:
  unordered_map<string, Node*> nodes; 

  const int NUM_DATA_POINTS = 55863; // gotten from Stanford SNAP
}; 