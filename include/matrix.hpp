#pragma once

#include "util.hpp"

#include <fstream>
#include <unordered_map>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

class Matrix {
public:
  Matrix(std::string file_name, int n);
  ~Matrix();
  std::string name(int a); 
  int size();

    /**
 * @brief Take 2 strings and check if they are connected (adjacent)
 * @param a the first string and @param b the second string to which we want to check connectedness
 * @return a bool saying if the two strings are connected
 */   
  bool isConnectedTo(std::string a, std::string b);
  std::unordered_map<std::string,int> getReddits();

 
  bool isConnectedTo(int a, int b); 



  /**
 * @brief construct a matrix that contains the shortest paths between various pairs of nodes
 * @param .No paramaters
 * @return Void
 */  
  void shortestPath(); 


  /**
 * @brief Build a path between two nodes using the shortest path function
 * @param a the first index and @param b the second index between which we want to construct a path
 * @return a vector that contains the names of the nodes visited along the path
 */  
  std::vector<std::string> constructPath(int a, int b); 
  std::vector<std::string> constructPath(std::string a, std::string b); 
  bool isAllConnected(); 


  /**
 * @brief Using Brandes' algorithm, calculate the inputted number of most central nodes in the graph
 * @param num the number of most "central" nodes we want to find
 * @return a vector containing the names of the most central nodes
 */  
  std::vector<std::string> mostCentral(size_t num); 

  bool** getMatrix() const; 
  int** getDist() const;  
  int getSize() const;  
  void printAllPaths();
private:
  int calcBetweeness(std::string a); 
  int calcBetweeness(int a); 

  bool calcedShortestPath = false; 

  bool** matrix;
  int** distMatrix;
  int** next; 
  std::unordered_map<std::string,int> indices;
  std::unordered_map<int,std::string> names;
  int n;
};