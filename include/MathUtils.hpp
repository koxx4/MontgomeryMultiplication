/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/


#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

struct GcdResult {
    int value;
    int firstCof;
    int secondCof;
};

int gcd(int a, int b, int& x, int& y);

GcdResult* gcd(int a, int b);

long timeAvg(std::vector<long>& measuers);

uint64_t randomInBounds(uint64_t low, uint64_t high);

__uint128_t random128InBounds(__uint128_t low, __uint128_t high);