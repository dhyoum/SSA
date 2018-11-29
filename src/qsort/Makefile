XX  = g++

CXXFLAGS =
CXXFLAGS += -O2 -g -std=c++11 -Wall

all: main

main: main.cpp
	$(CXX) $^ -o $@

input.txt:
	@-rm -rf input.txt
	$(shell echo $(RANDOM))
	@echo 100 >> input.txt;
	seq 100 | awk 'BEGIN{srand()} {print(int(rand()*100))}' >> input.txt

test: main input.txt
	./main < input.txt

clean:
	-rm -rf *.o main input.txt
