#include "catch2/catch.hpp"
#include "processdata.hpp"
#include "tests_helper.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <algorithm>
#include <iostream>
/**
 * Build Matrix test cases
 */
TEST_CASE("emtpy csv build matrix", "[matrix][data]") {
  REQUIRE_NOTHROW("../tests/test_data/empty.csv"); 
}

TEST_CASE("test2.csv build matrix", "[matrix][data]") {
  Matrix m("../tests/test_data/test2.csv",0); 
}
TEST_CASE("Full scale build matrix", "[matrix][data]") {
  Matrix m("../data/new_fixed_data.csv",1997); 
  // cannot check the whole graph so check that specific nodes in the graph
  // check for nodes listed early in the dataset
  const std::unordered_map<string, int>& test = m.getReddits(); 
  REQUIRE(test.find("leagueoflegends") != test.end()); 
  REQUIRE(test.find("soccer") != test.end()); 
  REQUIRE(test.find("cfb") != test.end()); 
  REQUIRE(test.find("gamedev") != test.end()); 
  REQUIRE(test.find("dogecoin") != test.end()); 
  // check nodes in middle of dataset
  REQUIRE(test.find("canada") != test.end()); 
  REQUIRE(test.find("iran") != test.end()); 
  REQUIRE(test.find("civcraft") != test.end()); 
  REQUIRE(test.find("steam") != test.end()); 
  REQUIRE(test.find("mobileweb") != test.end()); 
  // check nodes at end of dataset
  REQUIRE(test.find("anxiety") != test.end()); 
  REQUIRE(test.find("dataisbeautiful") != test.end()); 
  REQUIRE(test.find("mgtow") != test.end());
}
TEST_CASE("Check For Connections", "[matrix][data]") {
  Matrix m("../data/new_fixed_data.csv",1997); 
  std::ifstream ifs("../data/new_fixed_data.csv");
  // cannot check the whole graph so check that specific nodes in the graph
  // check for nodes listed early in the dataset
  bool**b=m.getMatrix();
  std::string line;

  std::getline(ifs, line); 
  while(std::getline(ifs, line)) {
    std::vector<std::string> vect = splitLine(line); 
    std::string a = vect[0]; 
    std::string b = vect[1]; 
    REQUIRE(m.isConnectedTo(a,b));
  }
}
TEST_CASE("Check Valid Paths", "[matrix][apsp][data]") {
  Matrix m("../data/new_fixed_data.csv",1997); 
  // cannot check the whole graph so check that specific nodes in the graph
  // check for nodes listed early in the dataset
  m.shortestPath();
  int**d=m.getDist();
  for(size_t i=0;i<m.getSize();i++)
  {
    for(size_t j=i+1;j<m.getSize();j++)
    {
      bool k=d[i][j]==INT_MAX||d[i][j]==(m.constructPath(i,j).size()-1);
      if(!k)
      {
          std::cout<<i<<" "<<j<<" "<<m.name(i)<<" "<<m.name(j)<<" "<<d[i][j]<<" "<<m.constructPath(i,j).size()<<std::endl;
      }
      REQUIRE(k);
    }
  }
}

TEST_CASE("adjacency matrix test", "[matrix][data]") {
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

TEST_CASE("adjacency matrix test2", "[matrix][data]") {
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

TEST_CASE("Shortest distance matrix test1", "[matrix][apsp][data]") {
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

TEST_CASE("Shortest distance matrix test2", "[matrix][apsp][data]") {
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

TEST_CASE("betwness centrality public test", "[matrix][data]") {
  int n = 5;
  Matrix m("../tests/test_data/sample_data_2.csv", n);
}

TEST_CASE("Check for Correct Path", "[matrix][apsp][data]") {
  Matrix m("../data/new_fixed_data.csv",1997); 
  m.shortestPath();
  int**d=m.getDist();
  bool**con=m.getMatrix();
  srand (time(NULL));
  for(size_t a=0;a<1997;a++)
  {
    for(size_t b=0;b<1997;b++)
    {
        if(d[a][b]!=INT_MAX)
        {
            std::vector<std::string>r=m.constructPath(a,b);
            for(size_t j=0;j<r.size()-1;j++)
            {
                REQUIRE(m.isConnectedTo(r[j],r[j+1]));
            }
        }
    }
  }
}

//testcommit
