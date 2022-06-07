/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/

#include <cmath>
#include <cstdio>

#include "../include/MontgomeryNumber.hpp"
#include "../include/MontgomeryBenchmark.hpp"

#define R_POWER 2
#define ODD_N 5001

void printfMontgomery(MontgomeryNumber& mNum) {

    printf("Montgomery number: r{%ld}. Untransformed {%ld}, transformed {%ld}.\n",
     mNum.getR(), mNum.getOriginal(), mNum.getTransformed());
}

void printfMontgomeryBrief(MontgomeryNumber& mNum) {

    printf("M{%ld},{%ld}",
     mNum.getR(), mNum.getTransformed());
}

void tests() {

    printf("transformingIntoMontgomeryBenchmark: %ld ns\n",
        Tests::transformingIntoMontgomeryBenchmark(20, 5, UINT16_MAX, 5000));

    printf("reducingMontgomeryBenchmark: %ld ns\n",
        Tests::reducingMontgomeryBenchmark(20, 5, UINT16_MAX, 5000));

    printf("addMontgomeryBenchmark: %ld ns\n",
        Tests::addMontgomeryBenchmark(5000));

    printf("subMontgomeryBenchmark: %ld ns\n",
        Tests::subMontgomeryBenchmark(5000));

    printf("divMontgomeryBenchmark: %ld ns\n",
        Tests::divMontgomeryBenchmark(5000));

    printf("mulMontgomeryBenchmark: %ld ns\n",
        Tests::mulMontgomeryBenchmark(5000));

    printf("normalModuloMulBenchmark: %ld ns\n",
        Tests::normalModuloMulBenchmark(5000));

    printf("normalModuloMulSequenceBenchmark: %ld ns %ld numbers\n",
        Tests::normalModuloMulSequenceBenchmark(UINT16_MAX, UINT32_MAX - 1, 10000, 1000), 10000L);

    printf("mulMontgomerySequenceBenchmark: %ld ns, sequence %ld numbers\n",
        Tests::mulMontgomerySequenceBenchmark(UINT16_MAX, UINT32_MAX - 1, 10000, 1000), 10000L);
}


int main() {

    MontgomeryNumber m1(20, R_POWER, ODD_N);
    MontgomeryNumber m2(30, R_POWER, ODD_N);
    MontgomeryNumber m3(2, R_POWER, ODD_N);
    MontgomeryNumber m4(10, R_POWER, ODD_N);

   printfMontgomery(m1);
   printfMontgomery(m2);
   printfMontgomery(m3);
   printfMontgomery(m4);

    printf("Montgomery number 1 reduced: {%ld}.\n", m1.getUntransformed());

    printf("Montgomery number 2 reduced: {%ld}.\n", m2.getUntransformed());

    m1.add(m2);
    printf("M1 + M2: {%ld}, reduce{%ld}\n", m1.getTransformed(), m1.getUntransformed());

    m1.sub(m4);
    printf("M1 - M4: {%ld}, reduce{%ld}\n", m1.getTransformed(), m1.getUntransformed());

    m1.mul(m3);
    printf("M1 * M3: {%ld}, reduce{%ld}\n", m1.getTransformed(), m1.getUntransformed());

    m1.div(m3);
    printf("M1 / M3: {%ld}, reduce{%ld}\n", m1.getTransformed(), m1.getUntransformed());


    tests();

    return 0;
}