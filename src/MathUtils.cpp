#include "../include/MathUtils.hpp"
#include <cstdint>
#include <ctime>

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

long timeAvg(std::vector<long>& measures) {

    long sum = 0;

    for(long& measure : measures) {
        sum += measure;
    }

    return static_cast<long>(sum / measures.size());
}

uint64_t randomInBounds(uint64_t low, uint64_t high) {

    srand(time(NULL));

    return rand() % (high - low) + high;
}