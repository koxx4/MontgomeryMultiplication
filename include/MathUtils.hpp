/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/


#pragma once

#include <cmath>

struct GcdResult {
    int value;
    int firstCof;
    int secondCof;
};

int gcd(int a, int b, int& x, int& y);
GcdResult* gcd(int a, int b);