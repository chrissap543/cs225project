#include "catch/catch.hpp"
#include "graph.hpp"
#include "node.hpp"

TEST_CASE("Build graph", "[graph][data]") {
  REQUIRE(true); 
}

std::unordered_map<string, Node*> map;
Node a("LOL");
Node b("NBA");
Node c("behindthegifs");
Node d("wowthissubexists");
a.addNeighbor(&c);
c.addNeighbor(&a);
c.addNeighbor(&d);
d.addNeighbor(&c);
b.addNeighbor(&c);
c.addNeighbor(&b);
map.insert({"LOL", &a});
map.insert({"NBA", &b});
map.insert({"behindthegifs", &c});
map.insert({"wowthissubexists", &d});
Graph g(map);