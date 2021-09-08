#include "main.hpp"
#include <string>
#include <iostream>
using namespace std;

bool Solution::isPalindrome(int x){
    string xStr = to_string(x);
    for (int i = 0; i < xStr.size()/2; i++){
        if (xStr[i] != xStr[xStr.size() - 1 - i]){
            return false;
        }
    }
    return true;
}