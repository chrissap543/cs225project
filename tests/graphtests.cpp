#include "catch2/catch.hpp"
#include "processdata.hpp"

#include <algorithm>

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
TEST_CASE("emtpy csv build graph", "[graph][data]") {
  REQUIRE_NOTHROW("../tests/test_data/empty.csv"); 
}
TEST_CASE("test1.csv build graph", "[graph][data]") {
  Graph g = buildGraph("../tests/test_data/test1.csv"); 

  Node* a1 = new Node("a1"); 
  Node* a2 = new Node("a2"); 
  Node* a3 = new Node("a3"); 
  Node* a4 = new Node("a4"); 

  a1->addNeighbor(a2); 
  a2->addNeighbor(a1); 
  a3->addNeighbor(a1); 
  a1->addNeighbor(a4); 

  std::unordered_map<string, Node*> map; 
  map.insert({"a1", a1}); 
  map.insert({"a2", a2}); 
  map.insert({"a3", a3}); 
  map.insert({"a4", a4}); 

  const std::unordered_map<string, Node*>& test = g.getNodes(); 
  for(auto it = map.begin(); it != map.end(); ++it) {
    REQUIRE(test.find(it->first) != test.end()); 
    REQUIRE(*test.find(it->first)->second == *it->second); 
  }
}
TEST_CASE("test2.csv build graph", "[graph][data]") {
  Graph g = buildGraph("../tests/test_data/test2.csv"); 
}
TEST_CASE("Full scale build graph", "[graph][data]") {
  Graph g = buildGraph("../data/fixed_data.csv"); 
  // cannot check the whole graph so check that specific nodes in the graph
  // check for nodes listed early in the dataset
  const std::unordered_map<string, Node*>& test = g.getNodes(); 
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
  REQUIRE(test.find("ripple") != test.end()); 
  REQUIRE(test.find("anxiety") != test.end()); 
  REQUIRE(test.find("dataisbeautiful") != test.end()); 
  REQUIRE(test.find("mgtow") != test.end()); 
}

/**
 * DFS test cases
 */
TEST_CASE("Small graph dfs1", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists"}; 
  std::vector<std::string> dfs = graph.dfs("LOL"); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
}
TEST_CASE("Small graph dfs2", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists"}; 
  std::vector<std::string> dfs = graph.dfs("behindthegifs"); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
}
TEST_CASE("Small graph dfs3", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists"}; 
  std::vector<std::string> dfs = graph.dfs("NBA"); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
}
TEST_CASE("Small graph dfs4", "[graph][traversal]") {
  Graph graph = buildSmallTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists"}; 
  std::vector<std::string> dfs = graph.dfs("wowthissubexists"); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
}

TEST_CASE("Small disconnected graph dfs1", "[graph][traversal]") {
  Graph graph = buildSmallDisconnectedTestGraph(); 
  std::vector<std::string> expected = {"LOL", "behindthegifs", "NBA", "wowthissubexists", "movies", "superman"}; 
  std::vector<std::string> dfs = graph.dfs("LOL"); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
}
TEST_CASE("Small disconnected graph dfs2", "[graph][traversal]") {
  Graph graph = buildSmallDisconnectedTestGraph(); 
  std::vector<std::string> expected = {"movies", "superman", "behindthegifs", "NBA", "wowthissubexists", "LOL"}; 
  std::vector<std::string> dfs = graph.dfs("movies"); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
}

TEST_CASE("Small random size graph dfs", "[graph][traversal]") {
  Graph graph = makeTestGraph(12);
  std::vector<std::string> expected = {"a", "l", "k", "h", "g", "f", "c", "d", "e", "j", "b", "i"}; 
  std::vector<std::string> dfs = graph.dfs("a"); 
  REQUIRE(dfs.size() == 12); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
  dfs = graph.dfs("d"); 
  for(std::string& str : expected)
    REQUIRE(std::find(dfs.begin(), dfs.end(), str) != dfs.end()); 
}
TEST_CASE("Small random size graph dfs2", "[graph][traversal]") {
  for (int i = 2; i < 26; i++) {
    Graph graph = makeTestGraph(i);
    REQUIRE(graph.dfs("a").size() == i);
  }
}

TEST_CASE("Full scale test", "[graph][traversal][data]") {
  Graph g = buildGraph("../data/fixed_data.csv"); 
  // cannot build whole dfs by hand
  // verify that certain nodes are in the traversal
  std::vector<std::string> dfs = g.dfs(); 
  const unordered_map<std::string, Node*>& map = g.getNodes(); 
  // check for nodes listed early in the dataset
  REQUIRE(std::find(dfs.begin(), dfs.end(), "leagueoflegends") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "soccer") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "cfb") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "gamedev") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "dogecoin") != dfs.end()); 
  // check nodes in middle of dataset
  REQUIRE(std::find(dfs.begin(), dfs.end(), "canada") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "iran") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "civcraft") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "steam") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "mobileweb") != dfs.end()); 
  // check nodes at end of dataset
  REQUIRE(std::find(dfs.begin(), dfs.end(), "ripple") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "anxiety") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "dataisbeautiful") != dfs.end()); 
  REQUIRE(std::find(dfs.begin(), dfs.end(), "mgtow") != dfs.end()); 
}