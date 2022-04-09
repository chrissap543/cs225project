#pragma once

#include <string>
#include <vector>

class Node {
public:
  Node(std::string name); 
  ~Node() = default; 

  std::string getName() const; 
  const std::vector<Node*>& getNeighbors() const; 

  void addNeighbor(Node* node); 
private:
  std::string name; 
  std::vector<Node*> neighbors;
}; 