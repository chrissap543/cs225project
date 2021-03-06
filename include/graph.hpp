#pragma once

#include "node.hpp"

#include <unordered_map>
#include <stack>
#include <algorithm>
#include <iostream>

using std::string; 
using std::unordered_map; 

class Graph {
public:
  Graph(unordered_map<string, Node*> nodes_); 
  ~Graph(); 

  const unordered_map<string, Node*>& getNodes() const; 
  const size_t getSize() const; 

/**
 * @brief runs dfs on the graph
 * Note that this will only work on the reddit dataset since we arbitrarily chose a starting node
 */
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
/**
 * @brief Returns a vector of the highest degree nodes in the graph
 * @param num the number of highest degree nodes to output
 * @return a vector of the highest degree nodes in the graph
 */ 
  std::vector<std::string> highestDegree(int num); 

private:
  unordered_map<string, Node*> nodes; 

  const int NUM_DATA_POINTS = 35576; // gotten from Stanford SNAP

  void dfsUtil(Node* start, std::vector<std::string>& path); 

};