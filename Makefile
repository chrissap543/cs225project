CXX=clang++
INCLUDES=-Iinclude/
CXXFLAGS=-std=c++20 -g -v 

exec: bin/exec
test: bin/tests

bin/exec: ./src/main.cpp ./src/node.cpp ./src/graph.cpp ./src/matrix.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@


clean: 
	rm -rf bin/*

.DEFAULT: exec