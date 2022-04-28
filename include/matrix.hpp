#pragma once

#include <fstream>
#include <map>
#include <string>

class Matrix {
public:
  Matrix();
  Matrix(std::fstream f);
  ~Matrix();
  std::string name(int a); 
  bool isConnectedTo(std::string a, std::string b);
private:
  bool** matrix;
  int** distMatrix;
  std::map<std::string,int> indices;
  std::map<int,std::string> names;
  int n;
};