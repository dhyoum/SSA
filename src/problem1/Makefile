CXX  = g++

CXXFLAGS =
CXXFLAGS += -O2 -g -std=c++11 -Wall

all: dfs bfs

dfs: dfs.cpp
	$(CXX) $^ -o $@

bfs: bfs.cpp
	$(CXX) $^ -o $@

clean:
	\rm -rf dfs bfs
