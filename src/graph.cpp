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

std::vector<std::string> Graph::dfs() {
  // one of the first one in csv (chosen arbitrarily)
  return dfs("ps4"); 
}

std::vector<std::string> Graph::dfs(std::string start) {
  return dfs(nodes[start]); 
}

std::vector<std::string> Graph::dfs(Node* start) {
  for(auto it = nodes.begin(); it != nodes.end(); ++it) {
    it->second->setStatus(false);
  }
  std::vector<std::string> path; 

  std::stack<Node*> s;
  s.push(start);
  while (!s.empty()) {
    Node* cur = s.top();
    path.push_back(cur->getName()); 
    s.pop();
    if (cur->getStatus() == false) {
      cur->setStatus(true);
    }
    std::vector<Node*> neighbors = cur->getNeighbors();
    for (int i = 0; i < neighbors.size(); i++) {
      if (neighbors[i]->getStatus() == false) {
  
        s.push(neighbors[i]);
      }
    }
  }
    for(auto it = nodes.begin(); it != nodes.end(); ++it) {
      if (it->second->getStatus() == false) {
        s.push(it->second);
        while (!s.empty()) {
          Node* cur = s.top();
          path.push_back(cur->getName()); 
          s.pop();
          if (cur->getStatus() == false) {
            cur->setStatus(true);
    }
    std::vector<Node*> neighbors = cur->getNeighbors();
    for (int i = 0; i < neighbors.size(); i++) {
      if (neighbors[i]->getStatus() == false) {
        s.push(neighbors[i]);
        }
      }
    }
  }
}

  return path; 
}
