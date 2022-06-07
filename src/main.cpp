/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/

#include <cmath>
#include <cstdio>

#include "../include/MontgomeryNumber.hpp"

#define R_POWER 3
#define ODD_N 5001

void printfMontgomery(MontgomeryNumber& mNum) {

    printf("Montgomery number: r{%ld}. Untransformed {%ld}, transformed {%ld}.\n",
     mNum.getR(), mNum.getOriginal(), mNum.getTransformed());
}

void printfMontgomeryBrief(MontgomeryNumber& mNum) {

    printf("M{%ld},{%ld}",
     mNum.getR(), mNum.getTransformed());
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

    return 0;
}