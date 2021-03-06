#include "processdata.hpp"

Graph buildGraph(std::string file_name) {
  std::ifstream ifs;
  ifs.open(file_name.c_str()); 

  std::unordered_map<std::string, Node*> mp;
  std::vector<std::string> test; 
  test.reserve(NUM_DATA_POINTS); 
  mp.reserve(NUM_DATA_POINTS); 
  std::string line; 
  std::getline(ifs, line); // skip header of csv
  while(std::getline(ifs, line)) {
    auto split = splitLine(line); // get the source, target
    std::string source = split.at(0), target = split.at(1);

    // neither created
    if(mp.find(source) == mp.end() && mp.find(target) == mp.end()) {
      Node* s_node = new Node(source); 
      Node* t_node = new Node(target);
      s_node->addNeighbor(t_node);  

      mp.insert({source, s_node}); 
      mp.insert({target, t_node}); 
      test.push_back(source);
      test.push_back(target);  
    }
    // source created, target not
    else if(mp.find(source) != mp.end() && mp.find(target) == mp.end()) {
      Node* t_node = new Node(target); 
      mp.at(source)->addNeighbor(t_node); 

      mp.insert({target, t_node});
      test.push_back(target);  
    }
    // source not, target created
    else if(mp.find(source) == mp.end() && mp.find(target) != mp.end()) {
      Node* s_node = new Node(source); 
      s_node->addNeighbor(mp.at(target)); 

      mp.insert({source, s_node});
      test.push_back(source);  
    }
    // both have been created
    else {
      mp.at(source)->addNeighbor(mp.at(target)); 
    }
  }

  // print each key in the map
  // for(auto it = mp.begin(); it != mp.end(); ++it) {
  //   std::cout << it->first << std::endl; 
  // }
  // std::cout << test.size() << std::endl; 

  return Graph(mp); 
}