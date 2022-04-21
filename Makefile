CXX=clang++
INCLUDES=-Iinclude/
CXXFLAGS=--std=c++1y -stdlib=libc++ -g

exec: bin/exec
test: bin/test

bin/exec: ./src/main.cpp ./src/graph.cpp ./src/node.cpp ./src/processdata.cpp ./src/matrix.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

bin/test: ./src/node.cpp ./src/graph.cpp ./src/processdata.cpp bin/graphtests.o bin/splittests.o bin/catchmain.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@
bin/graphtests.o: ./tests/graphtests.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@
bin/splittests.o: ./tests/splittests.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@
bin/catchmain.o: ./tests/catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -rf bin/*

.DEFAULT: exec