#include "catch/catch.hpp"
#include "graph.hpp"
#include "node.hpp"

TEST_CASE("Build graph", "[graph][data]") {
  REQUIRE(true); 
}
TEST_CASE("Small graph", "[graph]") {
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
  Graph g(map);
}