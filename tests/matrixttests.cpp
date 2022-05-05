#include "catch2/catch.hpp"
#include "tests_helper.h"
#include "matrix.hpp"
#include <iostream>

TEST_CASE("adjacency matrix test", "[matrix][traversal][data]") {
  int n = 4;
  Matrix m("../tests/test_data/sample_data_test.csv", n);
  bool** a = m.getMatrix();
  std::vector<std::vector<bool>> sol = 
            {{0, 1, 0, 0}, 
            {1, 0, 0, 0}, 
            {0, 0, 0, 1}, 
            {0, 0, 0, 0}};
  exactMatrix(a, sol, n);
}

TEST_CASE("adjacency matrix test2", "[matrix][traversal][data]") {
  int n = 5;
  Matrix m("../tests/test_data/sample_data_2.csv", n);
  bool** a = m.getMatrix();
  std::vector<std::vector<bool>> sol = 
    {{0, 1, 0, 0, 1},
    {0, 0, 1, 0, 0}, 
    {0, 0, 0, 1, 0}, 
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}};
  exactMatrix(a, sol, n); 
}

TEST_CASE("Shortest distance matrix test1", "[matrix][traversal][data]") {
  int n = 4;
  Matrix m("../tests/test_data/sample_data_test.csv", n);
  m.shortestPath(); 
  int** a = m.getDist();
  std::vector<std::vector<int>> sol = 
    {{2, 1, INT_MAX, INT_MAX},
    {1, 2, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, INT_MAX, 1},
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX}};
  exactDistMatrix(a, sol, n); 
}

TEST_CASE("Shortest distance matrix test2", "[matrix][traversal][data]") {
  int n = 5;
  Matrix m("../tests/test_data/sample_data_2.csv", n);
  m.shortestPath(); 
  int** a = m.getDist();
  std::vector<std::vector<int>> sol = 
    {{INT_MAX, 1, 2, 3, 1}, 
    {INT_MAX, INT_MAX, 1, 2, 3},
    {INT_MAX, INT_MAX, INT_MAX, 1, 2}, 
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1},
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}}; 
  exactDistMatrix(a, sol, n); 
}

TEST_CASE("betwness centrality public test", "[matrix][traversal][data]") {
  int n = 5;
  Matrix m("../tests/test_data/sample_data_2.csv", n);
}