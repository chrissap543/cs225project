#include "catch/catch.hpp"
#include "graph.hpp"
#include "node.hpp"

// standard small test graph
Graph buildSmallTestGraph() {
  std::unordered_map<string, Node*> map;
  Node* a = new Node("LOL");
  Node* b = new Node("NBA");
  Node* c = new Node("behindthegifs");
  Node* d = new Node("wowthissubexists");
  a->addNeighbor(c);
  c->addNeighbor(a);
  c->addNeighbor(d);
  d->addNeighbor(c);
  b->addNeighbor(c);
  c->addNeighbor(b);
  map.insert({"LOL", a});
  map.insert({"NBA", b});
  map.insert({"behindthegifs", c});
  map.insert({"wowthissubexists", d});
  return Graph(map); 
}
// builds graphs for n <= 26
Graph makeTestGraph(int n) {
  std::unordered_map<string, Node*> map; 
  for(int i = 0; i < n; i++) {
    std::string str(1, 'a'+i); 
    Node* n = new Node(str); 
    map.insert({n->getName(), n}); 
  }
  return Graph(map); 
}

TEST_CASE("Build graph", "[graph][data]") {
  REQUIRE(true); 
}
TEST_CASE("Small graph dfs", "[graph][traversal]") {
  Graph g = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists"}; 
  REQUIRE(g.dfs("LOL") == expected); 
}