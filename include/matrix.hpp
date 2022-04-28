#pragma once

#include <fstream>
#include <unordered_map>
#include <string>
#include <bits/stdc++.h>

class Matrix {
public:
  Matrix();
  ~Matrix();
  std::string name(int a); 
  bool isConnectedTo(std::string a, std::string b);

  void shortestPath(); 
  std::vector<std::string> constructPath(int a, int b); 
  std::vector<std::string> constructPath(std::string a, std::string b); 
private:
  bool** matrix;
  unsigned short int** distMatrix;
  unsigned short int** next; 
  std::unordered_map<std::string,int> indices;
  std::unordered_map<int,std::string> names;
  int n;
};