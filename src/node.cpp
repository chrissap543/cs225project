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
