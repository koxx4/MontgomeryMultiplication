/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/

#include "../include/MontgomeryNumber.hpp"
#include "../include/MathUtils.hpp"


MontgomeryNumber::MontgomeryNumber(uint64_t number, uint64_t rPower, uint64_t n) {
    
    this->rPower = rPower;
    this->r = (1 << rPower);
    this->n = n;
    this->originalNum = number;
    this->transformedNum = transformIntoMontgomerySpace(number); 
}


MontgomeryNumber::MontgomeryNumber(uint64_t rPower, uint64_t n) {

    this->r = (1 << rPower);
    this->n = n;
    this->originalNum = 0;
    this->transformedNum = transformIntoMontgomerySpace(0); 
}


MontgomeryNumber* MontgomeryNumber::sub(MontgomeryNumber& secondNum) {

    transformedNum -= secondNum.getTransformed();

    return this;
}

MontgomeryNumber* MontgomeryNumber::add(MontgomeryNumber& secondNum) {

    transformedNum += secondNum.getTransformed();
    
    return this;
}

MontgomeryNumber* MontgomeryNumber::mul(MontgomeryNumber& secondNum) {

    transformedNum = (reduce(transformedNum) * secondNum.getTransformed()) % n;
    
    return this;
}

MontgomeryNumber* MontgomeryNumber::div(MontgomeryNumber& secondNum) {

    transformedNum = ((transformedNum / secondNum.getTransformed()) << rPower) % n;

    return this;
}


uint64_t MontgomeryNumber::transformIntoMontgomerySpace(uint64_t number) {

    //original formula is (number * r) % n
    return (number << rPower) % n;
}

uint64_t MontgomeryNumber::reduce(int64_t number) {

    GcdResult* gcdResult = gcd(this->r, this->n);

    int& nCof = (gcdResult->secondCof);

    //uint64_t q = ((number % r) * nCof) % r;
    //We try to represent modulo with bitwise operations to be faster
    //https://stackoverflow.com/questions/3072665/bitwise-and-in-place-of-modulus-operator
    int64_t q = ((number & (r - 1)) * nCof) & (r - 1);

    // (number - q * n) / r
    int64_t a = ((int64_t)number - q * (int64_t)n) >> rPower;


    //if (a < 0) a += n;

    return a < 0 ? a + n : a;
}
