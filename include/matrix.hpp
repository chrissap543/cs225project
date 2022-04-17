#ifndef MATRIX_H
#define MATRIX_H

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
  std::map<std::string,int> indices;
  std::map<int,std::string> names;
  int n;
}; 

#endif // MATRIX_H