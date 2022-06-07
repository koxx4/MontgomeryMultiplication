#include "../include/MathUtils.hpp"

int gcd(int a, int b, int& x, int& y) {

    if (b == 0) {

        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

GcdResult* gcd(int a, int b) {
    int x, y = 0;
    int gcdValue = gcd(a, b, x, y);

    return new GcdResult {gcdValue, x, y};
}