#include <iostream>
#include <matrix.hpp>

int main() {
  std::fstream f("fixed_data.csv");
  Matrix m(f);
  std::cout<<m.isConnectedTo("nfl","cfb")<<std::endl;
}