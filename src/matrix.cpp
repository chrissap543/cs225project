#include "matrix.hpp"

using std::ifstream; 
using std::string; 
using std::pair; 

Matrix::Matrix(std::string file_name, int n): matrix(nullptr), distMatrix(nullptr), next(nullptr), n(n) {
  ifstream ifs(file_name);
  int i = 0;
  matrix= new bool*[n];
  for(size_t i=0;i<n;i++) {
    matrix[i]=new bool[n];
    for(size_t j = 0; j < n; j++)
      matrix[i][j] = false; 
  }
  std::string line; 
  std::getline(ifs, line); 
  while(std::getline(ifs, line)) {
    std::vector<std::string> vect = splitLine(line); 
    std::string a = vect[0]; 
    std::string b = vect[1]; 
    if(indices.find(a) == indices.end())
    {
      indices.insert(pair<string,int>(a,i));
      names.insert(pair<int,string>(i,a));
      i++;
    }
    if(indices.find(b) == indices.end())
    {
      indices.insert(pair<string,int>(b,i));
      names.insert(pair<int,string>(i,b));
      i++;
    }
    matrix[indices[a]][indices[b]] = true;
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

bool** Matrix::getMatrix() const { return matrix; }

int** Matrix::getDist() const { return distMatrix; }

bool Matrix::isConnectedTo(string a, string b) {
  return matrix[indices[a]][indices[b]];
}
bool Matrix::isConnectedTo(int a, int b) {
  return matrix[a][b]; 
}

std::unordered_map<std::string,int> Matrix::getReddits()
{
  return indices;
}

std::string Matrix::name(int a) {
  return names[a];
}

void Matrix::shortestPath() {
  calcedShortestPath = true; 
  
  distMatrix = new int*[n];
  next = new int*[n]; 
  for(size_t i = 0; i < n; i++) {
    distMatrix[i] = new int[n];
    next[i] = new int[n]; 
  }
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++) {
      distMatrix[i][j] = (matrix[i][j]) ? 1 : INT_MAX; 
      if(distMatrix[i][j] == INT_MAX)
        next[i][j] = -1; 
      else 
        next[i][j] = j; 
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (distMatrix[i][k] == INT_MAX || distMatrix[k][j] == INT_MAX)
          continue;
        if (distMatrix[i][j] > distMatrix[i][k] + distMatrix[k][j]) {
          distMatrix[i][j] = distMatrix[i][k] + distMatrix[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
}
std::vector<std::string> Matrix::constructPath(int a, int b) {
  if(!calcedShortestPath)
    shortestPath(); 
  if(next[a][b] == -1)
    return {};
  std::vector<std::string> path = {names[a]}; 
  //std::cout << isConnectedTo(a, b) << std::endl; 
  while(a != b) {
    a = next[a][b]; 
    path.push_back(names[a]); 
  }
  return path; 
}
std::vector<std::string> Matrix::constructPath(std::string a, std::string b) {
  return constructPath(indices[a], indices[b]); 
}

bool Matrix::isAllConnected() {
  if(!calcedShortestPath)
    shortestPath(); 
  bool foundInfinite = false; 
  int maxDist = -1; 
  int maxIndex1 = -1, maxIndex2 = -1; 
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++) {
      if(i == j)
        continue; 
      if(distMatrix[i][j] == INT_MAX) {
        std::cout << "No path between " << names.at(i) 
          << " and " << names.at(j) << "." << std::endl; 
      } else {
        if(distMatrix[i][j] > maxDist) {
          maxDist = distMatrix[i][j]; 
          maxIndex1 = i;
          maxIndex2 = j; 
        }
      }
    }
  }
  std::cout << "the max distance is " << maxDist << " between "
    << names[maxIndex1] << " and " << names[maxIndex2] << "." << std::endl; 
  return foundInfinite; 
}

std::vector<std::string> Matrix::mostCentral(size_t num) {
  if(!calcedShortestPath)
    shortestPath(); 
  // calculate centrality of all
  std::unordered_map<string, int> betweeness; 
  for(size_t i = 0; i < n; i++) {
    for(size_t j = 0; j < n; j++) {
      if(i == j)
        continue; 
      std::vector<std::string> path = constructPath(i, j); 
      if(path != std::vector<std::string>()) {
        for(size_t k = 1; k < path.size()-1; k++)
          betweeness[path[k]]++; 
      }
    }
  }
  // verify that all nodes have been added
  for(auto it = names.begin(); it != names.end(); ++it) {
    if(betweeness.find(it->second) == betweeness.end())
      betweeness.insert({it->second, 0}); 
  }

  std::vector<std::pair<string, int>> central; 
  auto it = betweeness.begin(); 
  for(size_t i = 0; i < num; i++) {
    central.push_back(*it); 
    ++it; 
  }
  std::sort(central.begin(), central.end(), [](std::pair<string, int>& left, std::pair<string, int>& right) {
    return left.second < right.second; 
  });  
  while(it != betweeness.end()) {
    if(it->second > central[0].second) {
      central[0] = *it; 
      std::sort(central.begin(), central.end(), 
        [](std::pair<string, int>& left, std::pair<string, int>& right) {
          return left.second < right.second; 
      }); 
    }
    ++it; 
  }
  std::vector<string> toReturn; 
  for(auto tmp = central.rbegin(); tmp != central.rend(); ++tmp) {
    toReturn.push_back(tmp->first); 
  }
  return toReturn; 
}

int Matrix::getSize() const
{
  return n;
}
