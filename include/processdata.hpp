#pragma once

#include "graph.hpp"
#include "node.hpp"
#include "util.hpp" 

#include <fstream>
#include <unordered_map>
#include <iostream>
#include <stack>

class ProcessData {
public:
  void floydWarshall();
  void shortestDistance(Node * first, Node * target);
  void betweenCenter(int centers);

private:

};
const int NUM_DATA_POINTS = 35776; // gotten from Stanford SNAP 

/**
 * @brief Takes a csv file and produces a graph
 * @param file_name the name of a csv file
 * @return A graph built off of the input file
 */
Graph buildGraph(std::string file_name); 