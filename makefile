.PHONY: all

all: 
	release

release:
	g++ -Wall -O1 src/main.cpp -o montgomery.out

debug:
	g++ -Wall -g src/main.cpp -o montgomery_debug.out
