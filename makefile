.PHONY: all

SOURCES = src/main.cpp src/MathUtils.cpp src/MontgomeryNumber.cpp src/MontgomeryBenchmark.cpp

all: 
	release

release:
	g++ -Wall -O3 $(SOURCES) -o montgomery.out

debug:
	g++ -Wall -g -O0 -fno-inline-functions $(SOURCES) -o montgomery_debug.out
