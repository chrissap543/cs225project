CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g

exec: bin/exec
test: bin/tests

bin/exec: ./src/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@