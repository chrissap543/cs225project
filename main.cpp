#include "graph.hpp"
#include "node.hpp"
#include "matrix.hpp"
#include "processdata.hpp"

#include <iostream>
#include <sstream>

void printHelp(char** argv); 
char* getFlagOption(char** begin, char** end, const std::string& option); 
bool hasFlag(char** begin, char** end, const std::string& option); 
int allPairsShortest(Matrix& m, int argc, char** argv); 
void checkConnectivity(Matrix& m); 
int printBetweeness(Matrix& m, int num); 

int main(int argc, char **argv) {
  if(argc < 2) {
    std::cerr << "Usage: " << argv[0] << " [flags] (use -h for help)" << std::endl; 
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
  bool newinput = false; 
  std::string input_file = "";
  if(hasFlag(argv, argv+argc, "-r")) {
    char* filename = getFlagOption(argv, argv+argc, "-r"); 
    if(!filename) {
      std::cerr << "No input file specified after flag" << std::endl; 
      return -1; 
    }
    input_file = filename; 
    newinput = true; 
  }

  // check for which algorithm to run
  bool foundAlgo = false, traversal = false, apsp = false, between = false; 
  if(hasFlag(argv, argv+argc, "-t")) {
    foundAlgo = true; 
    traversal = true; 
  }
  if(hasFlag(argv, argv+argc, "-f")) {
    if(foundAlgo) {
      std::cerr << "Run one algorithm at a time" << std::endl; 
      return -1; 
    }
    foundAlgo = true;
    apsp = true; 
  }
  int numCentral = 5; 
  if(hasFlag(argv, argv+argc, "-b")) {
    if(foundAlgo) {
      std::cerr << "Run one algorithm at a time" << std::endl; 
      return -1; 
    }
    foundAlgo = true; 
    between = true; 
    char* num = getFlagOption(argv, argv+argc, "-b"); 
    if(num && num[0] != '-') {
      // check that num numeric
      std::string s(num); 
      if(s.find_first_not_of("0123456789") == std::string::npos)
        numCentral = std::stoi(s); 
      else {
        std::cout << "Input a valid number for central nodes" << std::endl;
        return -1; 
      }
    }
  }

  if(!foundAlgo) {
    std::cerr << "Choose an algorithm to run" << std::endl; 
    return -1; 
  }

  if(traversal) {
    if(newinput) {
      Graph g = buildGraph(input_file); 
      g.dfs(); 
    } else {
      Graph g = buildGraph("../data/fixed_data.csv"); 
      g.dfs(); 
    }
  }

  if(apsp) {
    if(newinput) {
      Graph g = buildGraph(input_file); 
      Matrix m(input_file, g.getSize()); 
      if(allPairsShortest(m, argc, argv) == -1)
        return -1; 
    } else {
      Matrix m("../data/new_fixed_data.csv", 1997); 
      if(allPairsShortest(m, argc, argv) == -1)
        return -1; 
    }
  }

  if(between) {
    if(newinput) {
      Graph g = buildGraph(input_file); 
      Matrix m(input_file, g.getSize()); 
      if(printBetweeness(m, numCentral) == -1)
        return -1; 
    } else {
      Matrix m("../data/new_fixed_data.csv", 1997); 
      if(printBetweeness(m, numCentral) == -1)
        return -1; 
    }
  }

  if(tostdout) {
    std::cout.rdbuf(old_buf); 
    std::cout << ss.str(); 
  } else {
    // write to a file
    std::ofstream ofs(output_file); 
    ofs << ss.str(); 
  }
  return 0; 
}

void printHelp(char** argv) {
  std::cout << "Usage: " << argv[0] << "[flags]" << std::endl; 
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

int allPairsShortest(Matrix& m, int argc, char** argv) {
  m.shortestPath(); 
  char* first_subreddit = getFlagOption(argv, argv+argc, "-t"); 
  if(first_subreddit) {
    if(first_subreddit[0] == '-') { // hit another flag
      checkConnectivity(m); 
    } else {
      char* second_subreddit = getFlagOption(argv, argv+argc, first_subreddit); 
      if(second_subreddit) {
        std::vector<std::string> path = m.constructPath(first_subreddit, second_subreddit); 
        if(path == std::vector<std::string>({}))
          std::cout << "There is no path between these subreddits" << std::endl;
        else {
          for(std::string& str : path) {
            std::cout << str << std::endl; 
          }
        } 
      } else {
        std::cerr << "Must input two subreddits" << std::endl; 
        return -1; 
      }
    }
  } else {
    checkConnectivity(m); 
  }
  return 0; 
}

void checkConnectivity(Matrix& m) {
  bool ans = m.isAllConnected(); 
  if(ans) {
    std::cout << "All nodes have a path to all other nodes" << std::endl; 
  } else {
    std::cout << "Not all nodes have a path to all other nodes" << std::endl; 
  }
}

int printBetweeness(Matrix& m, int num) {
  if(num > m.size()) {
    std::cerr << "Tried to calculate more central nodes than the size of the graph" << std::endl; 
    return -1; 
  }
  std::vector<std::string> vect = m.mostCentral(num);
  for(std::string str : vect) {
    std::cout << str << std::endl; 
  }
  return 0; 
}