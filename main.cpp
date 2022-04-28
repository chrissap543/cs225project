#include "graph.hpp"
#include "node.hpp"
#include "matrix.hpp"
#include "processdata.hpp"
#include <iostream>
#include <string>

int main() {
  // std::unordered_map<string, Node*> map;
  // Node* a = new Node("LOL");
  // Node* b = new Node("NBA");
  // Node* c = new Node("behindthegifs");
  // Node* d = new Node("wowthissubexists");
  // Node* e = new Node("movies");
  // Node* f = new Node("superman");
  // a->addNeighbor(c);
  // c->addNeighbor(a);
  // c->addNeighbor(d);
  // d->addNeighbor(c);
  // b->addNeighbor(c);
  // c->addNeighbor(b);
  // e->addNeighbor(f);
  // f->addNeighbor(e);
  // map.insert({"LOL", a});
  // map.insert({"NBA", b});
  // map.insert({"behindthegifs", c});
  // map.insert({"wowthissubexists", d});
  // map.insert({"movies", e});
  // map.insert({"superman", f});
  // Graph g(map); 
  // auto mp = g.getNodes(); 
  // for(auto it = mp.begin(); it != mp.end(); ++it)
  //   std::cout << it->first << std::endl; 
  // std::vector<std::string> ans = g.dfs("LOL"); 
  Matrix mat; 
  mat.shortestPath(); 
  mat.printAllPaths(); 
}