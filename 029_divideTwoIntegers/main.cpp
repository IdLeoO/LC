#include "main.hpp"
#include <iostream>

using namespace std;

// bit shift
int Solution::divide(int dividend, int divisor){
    if (dividend == INT32_MIN && divisor == -1){
        return INT32_MAX;
    }
    if (divisor == INT32_MIN){
        if (dividend == INT32_MIN){
            return 1;
        }
        else {
            return 0;
        }
    }
    bool neg = ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0));
    double Adivisor = (divisor > 0)? divisor : - divisor;
    double Adividend = (dividend < 0) ? dividend : - dividend;
    unsigned int shift = 1;
    unsigned int sum = Adivisor;
    if (Adivisor > - Adividend){
        return 0;
    }
    while (sum < - Adividend){
        sum = sum << 1;
        shift = shift << 1;
    }
    if (sum != - Adividend){
        shift = shift >> 1;
        sum = sum >> 1;
    }
    if (neg) {
        shift = 0 - shift;
        Adivisor = 0 - Adivisor;
    }
    if (sum != - Adividend){
        shift += divide( - Adividend - sum, Adivisor);
    }
    return shift;
}
/*
int Solution::divide(int dividend, int divisor){
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}
*/
int main(int argc, char* argv[]){
    Solution sol;
    cout << sol.divide(7 , -3 ) << endl;
    return 0;
}