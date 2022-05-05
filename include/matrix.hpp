#pragma once

#include "util.hpp"

#include <fstream>
#include <unordered_map>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

class Matrix {
public:
  Matrix();
  ~Matrix();
  std::string name(int a); 
  int size();
   
  bool isConnectedTo(std::string a, std::string b);
  bool isConnectedTo(int a, int b); 

  void shortestPath(); 
  std::vector<std::string> constructPath(int a, int b); 
  std::vector<std::string> constructPath(std::string a, std::string b); 
  bool isAllConnected(); 

  std::vector<std::string> mostCentral(size_t num); 

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