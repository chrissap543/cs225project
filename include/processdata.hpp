#pragma once

#include "graph.hpp"

#include <fstream>
#include <unordered_map>
#include <sstream>
#include <iostream>

class ProcessData{
public:

  int depthFirstSearch(Node * start);
  void floydWarshall();
  void shortestDistance(Node * first, Node * target);
  void betweenCenter(int centers);

private:

};
const int NUM_DATA_POINTS = 55863; // gotten from Stanford SNAP 

Graph buildGraph(std::string file_name); 
std::vector<std::string> splitLine(std::string line); 