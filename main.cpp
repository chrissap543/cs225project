#include "graph.hpp"
#include "node.hpp"
#include "matrix.hpp"
#include "processdata.hpp"

#include <iostream>
#include <string>
#include <chrono>

using std::chrono::high_resolution_clock; 
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main() {
  auto t1 = high_resolution_clock::now(); 
  Matrix m; 
  auto t2 = high_resolution_clock::now(); 
  duration<double, std::milli> ms_double = t2 - t1;
  std::cout << "constructor completed in " << ms_double.count() 
    << "ms"  << std::endl; 

  t1 = high_resolution_clock::now(); 
  m.shortestPath(); 
  t2 = high_resolution_clock::now(); 
  ms_double = t2 - t1;
  std::cout << "floyd warshall completed in " << ms_double.count() 
    << "ms" << std::endl; 

  t1 = high_resolution_clock::now(); 
  std::vector<std::string> central = m.mostCentral(5); 
  t2 = high_resolution_clock::now(); 
  ms_double = t2 - t1; 
  std::cout << "betweeness completed in " << ms_double.count() 
    << "ms" << std::endl; 
  for(auto x : central)
    std::cout << x << std::endl; 
}