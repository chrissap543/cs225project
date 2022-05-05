#include "graph.hpp"
#include "node.hpp"
#include "matrix.hpp"
#include "processdata.hpp"

#include <iostream>
#include <sstream>

void printHelp(char** argv); 
char* getFlagOption(char** begin, char** end, const std::string& option); 
bool hasFlag(char** begin, char** end, const std::string& option); 

int main(int argc, char **argv) {
  if(argc < 2) {
    std::cerr << "Usage: " << argv[0] << "[flags] (use -h for help)" << std::endl; 
    return -1; 
  }

  // check for help flag
  if(hasFlag(argv, argv+argc, "-h")) {
    printHelp(argv); 
    if(argc > 2) {
      std::cerr << "Do not use help with other arguments" << std::endl;
      return -1; 
    }
    return 0; 
  }

  std::stringstream ss; 
  // redirect the buffer
  auto old_buf = std::cout.rdbuf(ss.rdbuf()); 
  bool tostdout = true; 
  // check for output flag
  std::string output_file = ""; 
  if(hasFlag(argv, argv+argc, "-o")) {
    char* filename = getFlagOption(argv, argv+argc, "-o"); 
    if(!filename) {
      std::cerr << "No output file specified after flag" << std::endl; 
      return -1; 
    }
    tostdout = false; 
    output_file = filename; 
  }

  // check for read flag
  std::string input_file = "";
  if(hasFlag(argv, argv+argc, "-r")) {
    char* filename = getFlagOption(argv, argv+argc, "-r"); 
    if(!filename) {
      std::cerr << "No input file specified after flag" << std::endl; 
      return -1; 
    }
    input_file = filename; 
  }

  // check for which algorithm to run
  bool foundAlgo = false; 
  if(hasFlag(argv, argv+argc, "-t")) {
    foundAlgo = true; 
  }
  if(hasFlag(argv, argv+argc, "-f")) {
    if(foundAlgo) {
      std::err << "Run one algorithm at a time" << std::endl; 
      return -1; 
    }
  }
  if(hasFlag(argv, argv+argc, "-b")) {
    if(foundAlgo) {
      std::err << "Run one algorithm at a time" << std::endl; 
      return -1; 
    }
  }

  if(tostdout) {
    std::cout.rdbuf(old_buf); 
    std::cout << ss.str() << std::endl; 
  } else {
    // write to a file
    std::ofstream ofs(output_file); 
    ofs << ss.str(); 
  }
  return 0; 
}

void printHelp(char** argv) {
  std::cout << "Usage: " << argv[0] << " [flags]" << std::endl; 
  std::cout << "Flags:\n-h\thelp" << std::endl; 
  std::cout << "-t\tdepth first search" << std::endl; 
  std::cout << "-f\tFloyd-Warshall" << std::endl; 
  std::cout << "-b\tbetweeness centrality" << std::endl; 
  std::cout << "-o\toutput to a file" << std::endl; 
  std::cout << "-r\tread from a file" << std::endl; 
}

char* getFlagOption(char** begin, char** end, const std::string& option) {
  auto it = std::find(begin, end, option); 
  if(it != end && ++it != end)
    return *it; 
  return 0; 
}
bool hasFlag(char** begin, char** end, const std::string& option) {
  return std::find(begin, end, option) != end; 
}