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

//simple disconnected graph
Graph buildSmallDisconnectedTestGraph() {
  std::unordered_map<string, Node*> map;
  Node* a = new Node("LOL");
  Node* b = new Node("NBA");
  Node* c = new Node("behindthegifs");
  Node* d = new Node("wowthissubexists");
  Node* e = new Node("movies");
  Node* f = new Node("superman");
  a->addNeighbor(c);
  c->addNeighbor(a);
  c->addNeighbor(d);
  d->addNeighbor(c);
  b->addNeighbor(c);
  c->addNeighbor(b);
  e->addNeighbor(f);
  f->addNeighbor(e);
  map.insert({"LOL", a});
  map.insert({"NBA", b});
  map.insert({"behindthegifs", c});
  map.insert({"wowthissubexists", d});
  map.insert({"movies", e});
  map.insert({"superman", f});
  return Graph(map); 
}
// builds disconnected graph of n nodes for n <= 26
Graph makeTestGraph(int n) {
  std::unordered_map<string, Node*> map; 
  for(int i = 0; i < n; i++) {
    std::string str(1, 'a'+i); 
    Node* n = new Node(str); 
    map.insert({n->getName(), n}); 
  }
  return Graph(map); 
}

/**
 * Build graph test cases
 */
TEST_CASE("Build graph", "[graph][data]") {
  REQUIRE(true); 
}

/**
 * DFS test cases
 */
TEST_CASE("Small graph dfs", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists"}; 
  REQUIRE(graph.dfs("LOL") == expected);

}
TEST_CASE("Small graph dfs2", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"behindthegifs", "NBA", "wowthissubexists", "LOL"}; 
  REQUIRE(graph.dfs("behindthegifs") == expected); 

}
TEST_CASE("Small graph dfs3", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"NBA", "behindthegifs", "wowthissubexists", "LOL"}; 
  REQUIRE(graph.dfs("NBA") == expected); 
 
}
TEST_CASE("Small graph dfs4", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"wowthissubexists", "behindthegifs", "NBA", "LOL"}; 
  REQUIRE(graph.dfs("wowthissubexists") == expected); 

}
TEST_CASE("Small disconnected graph dfs", "[graph][traversal]") {
  Graph graph = buildSmallDisconnectedTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists", "movies", "superman"}; 
  REQUIRE(graph.dfs("LOL") == expected);
}
TEST_CASE("Small disconnected graph dfs2", "[graph][traversal]") {
  Graph graph = buildSmallDisconnectedTestGraph(); 
  std::vector<std::string> expected = {"movies", "superman", "behindthegifs", "NBA", "wowthissubexists", "LOL"}; 
  REQUIRE(graph.dfs("movies") == expected);
}
TEST_CASE("Small random size graph dfs", "[graph][traversal]") {
  Graph graph = makeTestGraph(12);
  REQUIRE(graph.dfs("a").size() == 12);
  std::vector<std::string> expected = {"a", "l", "k", "h", "g", "f", "c", "d", "e", "j", "b", "i"}; 
  REQUIRE(graph.dfs("a") == expected);
  std::vector<std::string> exPected = {"d", "l", "k", "h", "g", "f", "c", "e", "j", "b", "i", "a"};
  REQUIRE(graph.dfs("d") == exPected);
}
TEST_CASE("Small random size graph dfs2", "[graph][traversal]") {
  for (int i = 2; i < 26; i++) {
    Graph graph = makeTestGraph(i);
    REQUIRE(graph.dfs("a").size() == i);
  }
}