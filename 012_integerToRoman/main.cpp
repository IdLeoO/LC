#include "main.hpp"
#include <vector>
#include <iostream>
using namespace std;

string Solution::intToRoman(int num){
    vector<int> base = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> outBase = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int index = 0;
    string result = "";
    while (index < base.size()){
        if (num >= base[index]){
            result += outBase[index];
            num -= base[index];
        }
        else{
            index ++;
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    Solution sol;
    cout << sol.intToRoman(atoi(argv[1])) << endl;
    return 0;
}