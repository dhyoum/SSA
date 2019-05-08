CXX  = g++

CXXFLAGS =
CXXFLAGS += -O2 -g -std=c++11 -Wall

all: main

main: main.cpp
	$(CXX) $^ -o $@

test: main input.txt
	./main < input.txt

clean:
	-rm -rf *.o main
