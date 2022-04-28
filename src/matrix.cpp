#include "matrix.hpp"

using std::fstream; 
using std::string; 
using std::pair; 

Matrix::Matrix(): matrix(nullptr), distMatrix(nullptr), next(nullptr), n(35776) {
  fstream f("../data/fixed_data.csv");
  int i=0;
  matrix= new bool*[n];
  for(size_t i=0;i<n;i++) {
    matrix[i]=new bool[n];
  }
  while(f.peek()!=EOF) {
    int x;
    std::string a,b;
    f>>x>>a>>b;
    if(indices.count(a))
    {
      indices.insert(pair<string,int>(a,i));
      names.insert(pair<int,string>(i,a));
      i++;
    }
    if(indices.count(b))
    {
      indices.insert(pair<string,int>(b,i));
      names.insert(pair<int,string>(i,b));
      i++;
    }
    matrix[indices[a]][indices[b]]=true;
  }
}

Matrix::~Matrix() {
  for(size_t i = 0; i < n; i++) {
    delete[] matrix[i];
    if(distMatrix != nullptr && distMatrix[i] != nullptr)
      delete[] distMatrix[i];
    if(next != nullptr && next[i] != nullptr) 
      delete[] next[i];
  }
  delete[] matrix;
  if(distMatrix != nullptr) delete[] distMatrix; 
  if(next != nullptr) delete[] next; 
}

bool Matrix::isConnectedTo(string a, string b) {
  return matrix[indices[a]][indices[b]];
}
std::string Matrix::name(int a) {
  return names[a];
}

void Matrix::shortestPath() {
  distMatrix = new int*[n];
  next = new int*[n]; 
  for(size_t i = 0; i < n; i++) {
    distMatrix[i] = new int[n];
    next[i] = new int[n]; 
  }
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++) {
      if(matrix[i][j]) {
        distMatrix[i][j] = 1; 
        next[i][j] = j; 
      } else {
        distMatrix[i][j] = INT_MAX; 
        next[i][j] = -1; 
      }
    }
  }
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++) {
      for(size_t k = 0; k < n; k++) {
        if(distMatrix[j][i] == INT_MAX || distMatrix[i][k] == INT_MAX)
          continue; 
        if((distMatrix[j][k]>distMatrix[j][i]+distMatrix[i][k])) {
          distMatrix[j][k]=distMatrix[j][i]+distMatrix[i][k];
          next[j][k] = distMatrix[j][i]; 
        }
      }
    }
  }
}
std::vector<std::string> Matrix::constructPath(int a, int b) {
  if(next[a][b] == -1)
    return {};
  std::vector<std::string> path = {names[a]}; 
  while(a != b) {
    a = next[a][b]; 
    path.push_back(names[a]); 
  }
  return path; 
}
std::vector<std::string> Matrix::constructPath(std::string a, std::string b) {
  return constructPath(indices[a], indices[b]); 
}

void Matrix::printAllPaths() {
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++)
      std::cout << distMatrix[i][j] << " "; 
    std::cout << std::endl; 
  }
}