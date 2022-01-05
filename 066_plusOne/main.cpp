#include "main.hpp"
#include <iostream>

using namespace std;

vector<int> Solution::plusOne(vector<int> & digits){
    int idx = digits.size() - 1;
    while (idx >= 0){
        int carry = (digits[idx] + 1) > 9 ?  1: 0;
        digits[idx] = (digits[idx] + 1 > 9) ? digits[idx] - 9 : digits[idx] + 1;
        if (idx == 0 && carry == 1){
            digits.insert(digits.begin(), 1);
            break;
        }
        if (carry == 1) idx --;
        else break;
    }
    return digits;
}

int main(int argc, char* argv[]){
    vector<int> digits = {1, 2, 9};
    Solution sol;
    for (auto &x : sol.plusOne(digits)){
        cout << x << endl;
    }
}