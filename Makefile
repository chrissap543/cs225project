CXX=clang++
INCLUDES=-Iinclude/
CXXFLAGS=--std=c++11 -g

exec: bin/exec
test: bin/tests

bin/exec: ./src/main.cpp ./src/graph.cpp ./src/node.cpp ./src/processdata.cpp ./src/matrix.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

clean: 
	rm -rf bin/*

.DEFAULT: exec
