#include "graph.hpp"

using std::string; 
using std::unordered_map; 

Graph::Graph(unordered_map<string, Node*> nodes_): nodes(nodes_) { }

Graph::~Graph() {
  for(auto ele : nodes) {
    if(ele.second != nullptr) {
      delete ele.second; 
      ele.second = nullptr; 
    }
  }
}

const unordered_map<string, Node*>& Graph::getNodes() const { return nodes; }
const size_t Graph::getSize() const { return nodes.size(); }

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
  dfsUtil(start, path); 
  for(auto it = nodes.begin(); it != nodes.end(); ++it) {
    if(it->second->getStatus() == false)
      dfsUtil(it->second, path); 
  }
  return path; 
}

void Graph::dfsUtil(Node* start, std::vector<std::string>& path) {
  std::stack<Node*> s; 
  s.push(start); 
  while (!s.empty()) {
    Node* cur = s.top();
    s.pop();
    if (cur->getStatus() == false) {
      std::cout << cur->getName() << std::endl; 
      path.push_back(cur->getName()); 
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

std::vector<string> Graph::highestDegree(int num) {
  // build a map of nodes and sizes
  unordered_map<string, unsigned int> degrees; 
  for(auto it = nodes.begin(); it != nodes.end(); ++it)
    degrees.insert({it->first, it->second->getNeighbors().size()}); 
  // add the first num elements vector
  std::vector<std::pair<string, unsigned int>> highestDeg; 
  auto it = degrees.begin(); 
  for(size_t i = 0; i < num; i++) {
    highestDeg.push_back(*it); 
    ++it; 
  }
  std::sort(highestDeg.begin(), highestDeg.end(), [](std::pair<string, unsigned int>& left, std::pair<string, unsigned int>& right) {
    return left.second < right.second; 
  }); 
  while(it != degrees.end()) {
    if(it->second > highestDeg[0].second) {
      highestDeg[0] = *it; 
      std::sort(highestDeg.begin(), highestDeg.end(), [](std::pair<string, unsigned int>& left, std::pair<string, unsigned int>& right) {
        return left.second < right.second; 
      });
    }
    ++it; 
  }
  std::vector<string> toReturn; 
  for(auto x : highestDeg)
    toReturn.push_back(x.first); 
  return toReturn; 
}