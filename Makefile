CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g

exec: bin/exec
test: bin/tests

bin/exec: ./src/main.cpp ./src/node.cpp ./src/graph.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@