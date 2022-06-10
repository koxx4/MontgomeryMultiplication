/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/

#pragma once

#include <cstdint>
#include <cstddef>
#include "../include/MontgomeryNumber.hpp"

#define DEFAULT_R_POWER 6
#define DEFAULT_ODD_N __UINT64_MAX__ // is odd

namespace Tests {

    uint64_t transformingIntoMontgomeryBenchmark(uint64_t from, uint64_t rPow, uint64_t n, size_t retries);
    uint64_t reducingMontgomeryBenchmark(uint64_t from, uint64_t rPow, uint64_t n, size_t retries);


    uint64_t addMontgomeryBenchmark(size_t retries);
    uint64_t subMontgomeryBenchmark(size_t retries);
    uint64_t divMontgomeryBenchmark(size_t retries);
    uint64_t mulMontgomeryBenchmark(size_t retries);
    uint64_t mulMontgomerySequenceBenchmark(uint64_t min, uint64_t max, size_t sqeLength, size_t retries);

    uint64_t normalModuloMulBenchmark(size_t retries);
    uint64_t normalModuloMulSequenceBenchmark(uint64_t min, uint64_t max, size_t sqeLength, size_t retries);
}



void runTests();