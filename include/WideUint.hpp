#pragma once

#include <cstdint>

struct wide_uint;

inline wide_uint* maxNumber(wide_uint* a, wide_uint* b);
inline wide_uint* minNumber(wide_uint* a, wide_uint* b);

// This structure is not really optimised - it is rather implemented to have more didactic value
struct wide_uint {

    uint8_t* bytes;
    uintmax_t width;

    wide_uint(uintmax_t bytesNum) {
        
        this -> bytes = new uint8_t[bytesNum] {0};
        this -> width = bytesNum;
    }

    wide_uint(uint8_t* bytes, uintmax_t bytesNum) {
        
        this -> bytes = bytes;
        this -> width = bytesNum;
    }

    static wide_uint* from8(uint8_t val) {

        wide_uint* num = new wide_uint(1);
        
        num->bytes[0] = val;

        return num;
    }

    static wide_uint* from16(uint16_t val) {

        wide_uint* num = new wide_uint(2);
        
        num->bytes[1] = (val >> 8);
        num->bytes[0] = val;

        return num;
    }

    static wide_uint* from32(uint32_t val) {
        

        wide_uint* num = new wide_uint(4);
        
        num->bytes[3] = (val >> 24);
        num->bytes[2] = (val >> 16);
        num->bytes[1] = (val >> 8);
        num->bytes[0] = val;

        return num;
    }

    uint8_t as8() {
        return this->width >= 1 ? this->bytes[0] : 0;
    }

    uint16_t as16() {

        if (this->width < 2)
            return as8();
        
        uint16_t result = 0;
        result |= this->bytes[0];
        result |= ((uint16_t)this->bytes[1]) << 8;

        return result;
    }

    uint32_t as32() {

        if (this->width < 4)
            return as16();
        
        uint32_t result = 0;
        result |= this->bytes[0];
        result |= ((uint32_t)this->bytes[1]) << 8;
        result |= ((uint32_t)this->bytes[2]) << 16;
        result |= ((uint32_t)this->bytes[3]) << 24;

        return result;
    }

    wide_uint add(wide_uint *num) {

        wide_uint* maxNum = maxNumber(this, num);
        wide_uint* minNum = minNumber(this, num);
        uintmax_t minNumWidth =  minNum -> width;
        uintmax_t maxNumWidth =  maxNum -> width;
        uintmax_t bytesLeft =  maxNum -> width;
        bool carry = false;

        wide_uint result {maxNumWidth + 1};
        
        for (uintmax_t i = 0; i < minNumWidth; i++) {

            if((i < minNumWidth - 1) && carry) {
                result.bytes[i + 1]++;
                carry = false;
            }
            
            result.bytes[i] = maxNum->bytes[i] + minNum->bytes[i];
            
            if (result.bytes[i] < maxNum->bytes[i])
                carry = true;
            
            bytesLeft--;
        }


        while (bytesLeft) {

            result.bytes[maxNumWidth - bytesLeft] = maxNum->bytes[maxNumWidth - bytesLeft];

            if (carry) {

                if (result.bytes[maxNumWidth - bytesLeft] & 255)
                    result.bytes[maxNumWidth - bytesLeft]++;
                else {
                    result.bytes[maxNumWidth - bytesLeft]++;
                    carry = false;
                }
            }

             bytesLeft--;
        }

        return result;
    }

    inline wide_uint* maxNumber(wide_uint* a, wide_uint* b) {

        return a -> width >= b -> width ? a : b;
    }

    inline wide_uint* minNumber(wide_uint* a, wide_uint* b) {

        return a -> width >= b -> width ? b : a;
    }

};
