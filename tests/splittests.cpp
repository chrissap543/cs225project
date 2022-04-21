#include "catch/catch.hpp"
#include "processdata.hpp"

TEST_CASE("Empty split", "[processing]") {
  std::string str = ""; 
  std::vector<std::string> expected; 
  REQUIRE(splitLine(str) == expected); 
}

TEST_CASE("One comma split", "[processing]") {
  std::string str = "a,b"; 
  std::vector<std::string> expected = {"b"}; 
  REQUIRE(splitLine(str) == expected); 
}

TEST_CASE("Two comma split 1", "[processing]") {
  std::string str = "a,b,c"; 
  std::vector<std::string> expected = {"b", "c"}; 
  REQUIRE(splitLine(str) == expected); 
}

TEST_CASE("Two comma split 2", "[processing]") {
  std::string str = "1234,12bca,bob967"; 
  std::vector<std::string> expected = {"12bca", "bob967"}; 
  REQUIRE(splitLine(str) == expected); 
}

TEST_CASE("Multiple comma split", "[processing]") {
  // note that our code does not contain data that has 
  // more than 2 commas, but this verifies further functionality
  std::string str = "12,a,a4,bca,13j6b,c032v"; 
  std::vector<std::string> expected = {"a", "a4", "bca", "13j6b", "c032v"}; 
  REQUIRE(splitLine(str) == expected); 
}

TEST_CASE("Trim whitespace 1", "[processing]") {
  std::string str = "a, c , ba, ab "; 
  std::vector<std::string> expected = {"c", "ba", "ab"}; 
  REQUIRE(splitLine(str) == expected); 
}