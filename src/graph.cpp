#include "graph.hpp"

using std::string; 

Graph::~Graph() {
  for(int i = 0; i < nodes.size(); i++){
    if(nodes.at(i) != nullptr)
      delete nodes.at(i); 
  }
}

void Graph::addNode(Node* node) {
  nodes.push_back(node); 
}

void Graph::addNode(string s) {
  nodes.push_back(new Node(s)); 
}