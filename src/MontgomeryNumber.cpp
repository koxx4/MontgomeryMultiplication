/*
* Montgomery numbers
* Piotr Wilk 259106, Damian Serwuszok 259201 
*/

#include "../include/MontgomeryNumber.hpp"
#include "../include/MathUtils.hpp"


MontgomeryNumber::MontgomeryNumber(uint64_t number, uint64_t rPower, uint64_t n) {
    
    this->rPower = rPower;
    this->r = (1 << rPower);
    this->rMinusOne = this->r - 1;
    this->n = n;
    this->originalNum = number;
    this->transformedNum = transformIntoMontgomerySpace(number);

    GcdResult* gcdResult = gcd(this->r, this->n);
    this->nCof = gcdResult->secondCof; 
    this->rInverse = gcdResult->firstCof;
    delete gcdResult; 
}


MontgomeryNumber::MontgomeryNumber(uint64_t rPower, uint64_t n) {

    this->r = (1 << rPower);
    this->rMinusOne = this->r - 1;
    this->n = n;
    this->originalNum = 0;
    this->transformedNum = transformIntoMontgomerySpace(0); 

    GcdResult* gcdResult = gcd(this->r, this->n);
    this->nCof = gcdResult->secondCof; 
    this->rInverse = gcdResult->firstCof;
    delete gcdResult; 
}


MontgomeryNumber* MontgomeryNumber::sub(MontgomeryNumber& secondNum) {

    transformedNum = (transformedNum - secondNum.getTransformed());

    return this;
}

MontgomeryNumber* MontgomeryNumber::add(MontgomeryNumber& secondNum) {

    transformedNum = (transformedNum + secondNum.getTransformed());
    
    return this;
}

MontgomeryNumber* MontgomeryNumber::mul(MontgomeryNumber& secondNum) {

    transformedNum = (reduce(transformedNum * secondNum.getTransformed()));
    
    return this;
}

MontgomeryNumber* MontgomeryNumber::div(MontgomeryNumber& secondNum) {

    transformedNum = ((transformedNum / secondNum.getTransformed()) << rPower);

    return this;
}


uint64_t MontgomeryNumber::transformIntoMontgomerySpace(uint64_t number) {

    //original formula is (number * r) % n
    return (number << rPower) % n;
}

uint64_t MontgomeryNumber::reduce(int64_t number) {

    //uint64_t q = ((number % r) * nCof) % r;
    //We try to represent modulo with bitwise operations to be faster
    //https://stackoverflow.com/questions/3072665/bitwise-and-in-place-of-modulus-operator
    int64_t q = ((number & rMinusOne) * nCof) & rMinusOne;

    // (number - q * n) / r
    int64_t a = ((int64_t)number - q * (int64_t)n) >> rPower;


    //if (a < 0) a += n;

    return a < 0 ? a + n : a;
}
