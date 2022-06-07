/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/


#pragma once

#include <cstdint>

class MontgomeryNumber {

public:

    //Note: rPower should be at least >= 2
    MontgomeryNumber(uint64_t rPower, uint64_t n);
    //Note: rPower should be at least >= 2
    MontgomeryNumber(uint64_t number, uint64_t rPower, uint64_t n);

    //Basic operation that can be performed on two montgomery numbers
    MontgomeryNumber* sub(MontgomeryNumber& secondNum);
    MontgomeryNumber* add(MontgomeryNumber& secondNum);
    MontgomeryNumber* mul(MontgomeryNumber& secondNum);
    MontgomeryNumber* div(MontgomeryNumber& secondNum);
    //Data access
    uint64_t getTransformed() { return transformedNum; };
    uint64_t getOriginal() { return originalNum; };
    uint64_t getUntransformed() { return reduce(transformedNum); };
    uint64_t getR() { return r; };
    
private:    

    uint64_t originalNum;
    uint64_t transformedNum;
    uint64_t rPower;
    uint64_t r;
    uint64_t n;

    uint64_t transformIntoMontgomerySpace(uint64_t number);
    uint64_t reduce(int64_t number);

};
