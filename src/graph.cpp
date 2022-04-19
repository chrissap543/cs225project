#include "graph.hpp"

using std::string; 
using std::unordered_map; 

Graph::Graph(unordered_map<string, Node*> nodes_): nodes(nodes_) {}

Graph::~Graph() {
  for(auto ele : nodes) {
    if(ele.second != nullptr) {
      delete ele.second; 
      ele.second = nullptr; 
    }
  }
}

const unordered_map<string, Node*>& Graph::getNodes() const { return nodes; }

void Graph::dfs() {
  // one of the first one in csv (chosen arbitrarily)
  dfs(nodes["ps4"]); 
}

void Graph::dfs(Node* start) {
  std::vector<bool> visited;
  visited.reserve(NUM_DATA_POINTS);
}