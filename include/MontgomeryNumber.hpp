/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/


#pragma once

#include <cstdint>

class MontgomeryNumber {

public:

    //Note: rPower should be at least >= 1
    MontgomeryNumber(uint64_t rPower, __uint128_t n);
    //Note: rPower should be at least >= 1
    MontgomeryNumber(__uint128_t number, uint64_t rPower, __uint128_t n);

    //Basic operation that can be performed on two montgomery numbers
    MontgomeryNumber* sub(MontgomeryNumber& secondNum);
    MontgomeryNumber* add(MontgomeryNumber& secondNum);
    MontgomeryNumber* mul(MontgomeryNumber& secondNum);
    MontgomeryNumber* div(MontgomeryNumber& secondNum);
    //Data access
    __uint128_t getTransformed() { return transformedNum; };
    __uint128_t getOriginal() { return originalNum; };
    __uint128_t getUntransformed() { return reduce(transformedNum); };
    __uint128_t getR() { return r; };
    
private:    

    __uint128_t originalNum;
    __uint128_t transformedNum;
    uint64_t rPower;
    __uint128_t r;
    __uint128_t rInverse;
    __uint128_t rMinusOne;
    __uint128_t nCof;
    __uint128_t n;

    __uint128_t transformIntoMontgomerySpace(__uint128_t number);
    __uint128_t reduce(__uint128_t number);

};
