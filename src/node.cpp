#include "node.hpp"

Node::Node(std::string name): name(name), hasVisited(false) {} 

std::string Node::getName() const {
  return name; 
}

const std::vector<Node*>& Node::getNeighbors() const {
  return neighbors; 
}

void Node::addNeighbor(Node* node) {
  neighbors.push_back(node); 
}

bool Node::getStatus() {
  return hasVisited;
}

void Node::setStatus(bool status) {
  hasVisited = status;
}

bool Node::operator==(const Node& n) const {
  if(name != n.name)
    return false; 
  if(neighbors.size() != n.neighbors.size())
    return false;
  std::vector<std::string> n1; 
  for(auto x : neighbors)
    n1.push_back(x->getName()); 
  std::vector<std::string> n2; 
  for(auto x : n.neighbors)
    n2.push_back(x->getName()); 
  for(size_t i = 0; i < neighbors.size(); i++) {
    if(std::find(n2.begin(), n2.end(), n1.at(i)) == n2.end())
      return false; 
  }
  return true; 
}