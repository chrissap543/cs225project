#pragma once

#include <string>
#include <vector>
#include <algorithm>

class Node {
public:
  Node(std::string name); 
  ~Node() = default; 

  std::string getName() const; 
  const std::vector<Node*>& getNeighbors() const; 

  void addNeighbor(Node* node); 
  bool getStatus();
  void setStatus(bool status);
  bool operator==(const Node& n) const; 

private:
  std::string name; 
  std::vector<Node*> neighbors;
  bool hasVisited;
}; 