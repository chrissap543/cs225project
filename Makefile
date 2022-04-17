CXX=clang++
INCLUDES=-Iinclude/
CXXFLAGS=-std=c++14 -g

exec: bin/exec
test: bin/tests

bin/exec: ./src/main.cpp ./src/matrix.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@


clean: 
	rm -rf bin/*

.DEFAULT: exec