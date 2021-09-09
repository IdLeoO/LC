#include "main.hpp"
#include <math.h>
#include <iostream>
using namespace std;
// Caution for the specific intepration of the algorithm such as --2 ++2 000-2...
int Solution::myAtoi(string s){
    string resultStr = "";
    double resultInt = 0;
    bool neg = false;
    bool pos = false;
    for (int i = 0; i < s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            resultStr.push_back(s[i]);
            pos = true;
        }
        else if ( s[i] == '-' && pos == false && neg == false){
            neg = true;
        }
        else if (s[i] == ' ' && pos == false && neg == false){}
        else if (s[i] == '+' && neg == false && pos == false){
            pos = true;
        }
        else{
            break;
        }
    }
    for (int i = resultStr.size() - 1; i >= 0; i--){
        double base = pow(10, i);
        switch (resultStr[resultStr.size() - 1 - i]){
            case '0': resultInt += 0 * base; break;
            case '1': resultInt += 1 * base; break;
            case '2': resultInt += 2 * base; break;
            case '3': resultInt += 3 * base; break;
            case '4': resultInt += 4 * base; break;
            case '5': resultInt += 5 * base; break;
            case '6': resultInt += 6 * base; break;
            case '7': resultInt += 7 * base; break;
            case '8': resultInt += 8 * base; break;
            case '9': resultInt += 9 * base; break;
            default: break;
        }
    }

    if (resultInt > 2147483648 - 2){
        if (resultInt > 2147483648 - 1 && neg == 0){
            resultInt = 2147483648 - 1;
            return resultInt;
        }
        else if (resultInt > 2147483648 && neg == 1){
            resultInt = 0 - 2147483648;
            return resultInt;
        }
    }
    if (neg == 1){
        return 0 - resultInt;
    }
    else {
        return resultInt;
    }
}

int main(int argc, char* argv[]){
    Solution sol;
    cout << sol.myAtoi(argv[1]) << endl;
}