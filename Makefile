CXX=clang++
INCLUDES=-Iinclude/
CXXFLAGS=--std=c++1y -stdlib=libc++ -g

exec: bin/exec
test: bin/tests

bin/exec: ./src/main.cpp ./src/node.cpp ./src/graph.cpp ./src/processdata.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

bin/tests: ./src/node.cpp ./src/graph.cpp ./src/processdata.cpp ./tests/graphtests.cpp bin/catchmain.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@
bin/catchmain.o: ./tests/catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -rf bin/*