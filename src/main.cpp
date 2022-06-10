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

    for (size_t i = 1; i <= 10000000; i *= 10)
    {
        printf("--------%ld numbers----------\n", i);

        long normal = Tests::normalModuloMulSequenceBenchmark(UINT16_MAX, UINT32_MAX - 1, i, 100);
        long montgomery = Tests::mulMontgomerySequenceBenchmark(UINT16_MAX, UINT32_MAX - 1, i, 100);
        printf("normal: %ld ns\n", normal);
        printf("montgomery: %ld ns\n", montgomery);
        printf("montgomery speed up: %.2f%\n", ((double)(normal - montgomery) / (double)normal) * 100);
    }
    


    //tests();

    return 0;
}