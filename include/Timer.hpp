/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/

#pragma once

#include <chrono>

class Timer {

public:

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        result = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
    }

    long getNanos() {
        return result.count();
    }

    long getMicros() {
        return std::chrono::duration_cast<std::chrono::microseconds>(result).count();
    }

    long getMilis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(result).count();
    }

    long getSeconds() {
        return std::chrono::duration_cast<std::chrono::seconds>(result).count();
    }

private:
    std::chrono::high_resolution_clock::time_point start {};
    std::chrono::nanoseconds result {};

};
