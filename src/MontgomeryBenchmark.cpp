/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/

#include "../include/MontgomeryBenchmark.hpp"
#include "../include/Timer.hpp"
#include "../include/MathUtils.hpp"

#include <vector>

namespace Tests {


uint64_t transformingIntoMontgomeryBenchmark(uint64_t from, uint64_t rPow, uint64_t n, uint64_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        Timer timer;
        MontgomeryNumber m(from, rPow, n);
        timer.stop();

        measures.push_back(timer.getNanos());
    }

    return timeAvg(measures);
}

uint64_t reducingMontgomeryBenchmark(uint64_t from, uint64_t rPow, uint64_t n, uint64_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        MontgomeryNumber m(from, rPow, n);

        Timer timer;
        m.getUntransformed();
        timer.stop();

        measures.push_back(timer.getNanos());
    }

    return timeAvg(measures);
}

uint64_t addMontgomeryBenchmark(uint64_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        MontgomeryNumber m1(randomInBounds(1, 50), DEFAULT_R_POWER, DEFAULT_ODD_N);
        MontgomeryNumber m2(randomInBounds(1, 50), DEFAULT_R_POWER, DEFAULT_ODD_N);
        
        Timer timer;
        m1.add(m2);
        timer.stop();

        measures.push_back(timer.getNanos());
    }

    return timeAvg(measures);
}

uint64_t subMontgomeryBenchmark(uint64_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        MontgomeryNumber m1(randomInBounds(1, 50), DEFAULT_R_POWER, DEFAULT_ODD_N);
        MontgomeryNumber m2(randomInBounds(1, 50), DEFAULT_R_POWER, DEFAULT_ODD_N);
        
        Timer timer;
        m1.sub(m2);
        timer.stop();

        measures.push_back(timer.getNanos());
    }

    return timeAvg(measures);
}

uint64_t divMontgomeryBenchmark(uint64_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        MontgomeryNumber m1(randomInBounds(UINT16_MAX, UINT16_MAX * 100), DEFAULT_R_POWER, DEFAULT_ODD_N);
        MontgomeryNumber m2(randomInBounds(UINT16_MAX, UINT16_MAX * 100), DEFAULT_R_POWER, DEFAULT_ODD_N);
        
        Timer timer;
        m1.div(m2);
        timer.stop();

        measures.push_back(timer.getNanos());
    }

    return timeAvg(measures);
}

uint64_t mulMontgomeryBenchmark(uint64_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        MontgomeryNumber m1(randomInBounds(UINT16_MAX, UINT16_MAX * 100), DEFAULT_R_POWER, DEFAULT_ODD_N);
        MontgomeryNumber m2(randomInBounds(UINT16_MAX, UINT16_MAX * 100), DEFAULT_R_POWER, DEFAULT_ODD_N);
        
        Timer timer;
        m1.mul(m2);
        timer.stop();

        measures.push_back(timer.getNanos());
    }

    return timeAvg(measures);
}

uint64_t mulMontgomerySequenceBenchmark(uint64_t min, uint64_t max, size_t sqeLength, size_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        uint64_t singleMeasures = 0;
        std::vector<MontgomeryNumber*> mNumbers;

        for (size_t i = 0; i < sqeLength; i++) {
            mNumbers.push_back(new MontgomeryNumber(random128InBounds((__uint128_t)INT64_MAX, (__uint128_t)INT64_MAX * 100), DEFAULT_R_POWER, DEFAULT_ODD_N));
        }

        MontgomeryNumber *m1 = mNumbers[0];

        for (MontgomeryNumber* mNum : mNumbers) {
            Timer timer;
            m1->mul(*mNum);
            timer.stop();
            singleMeasures += timer.getNanos();
        }

        for (MontgomeryNumber* mnum : mNumbers) delete mnum;
        
        measures.push_back(singleMeasures);    
    }

    return timeAvg(measures);
}

uint64_t normalModuloMulBenchmark(uint64_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        int64_t a = randomInBounds(UINT16_MAX, UINT16_MAX * 100);
        int64_t b = randomInBounds(UINT16_MAX, UINT16_MAX * 100);
        
        Timer timer;
        int64_t c = (a * b) % DEFAULT_ODD_N;
        timer.stop();

        //To prevent compiler from deleting c
        c++;

        measures.push_back(timer.getNanos());
    }

    return timeAvg(measures);
}

void mul(__int128_t& x, __int128_t& y) {
    x = (x * y) % DEFAULT_ODD_N;
}

uint64_t normalModuloMulSequenceBenchmark(uint64_t min, uint64_t max, size_t sqeLength, size_t retries) {

    std::vector<long> measures(retries);

    for (size_t i = 0; i < retries; i++) {

        uint64_t singleMeasures = 0;
        std::vector<__int128_t> numbers(sqeLength);

        for (auto& num : numbers) {
            num = random128InBounds((__uint128_t)INT64_MAX, (__uint128_t)INT64_MAX * 100);
        }

        __int128_t& n1 = numbers[0];

        for (auto& num : numbers) {
            Timer timer;
            mul(n1, num);
            timer.stop();
            singleMeasures += timer.getNanos();
        }

        measures.push_back(singleMeasures);
    }

    return timeAvg(measures);
}

}