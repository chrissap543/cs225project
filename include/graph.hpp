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

  std::vector<std::string> dfs(); 

  /**
 * @brief Take a name of the node and produces traversal path
 * @param start the name of the node we want to start traversal with
 * @return a vector represents traversal of the graph
 */
  std::vector<std::string> dfs(std::string start); 

  /**
 * @brief Take a starting node and produces traversal path
 * @param start the node we want to start traversal with
 * @return a vector represents traversal of the graph
 */
  std::vector<std::string> dfs(Node* start); 

private:
  unordered_map<string, Node*> nodes; 

  const int NUM_DATA_POINTS = 55863; // gotten from Stanford SNAP

  void dfsUtil(Node* start, std::vector<std::string>& path); 
}; 