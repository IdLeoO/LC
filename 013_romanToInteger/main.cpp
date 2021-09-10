#include "main.hpp"
#include <iostream>
#include <vector>
using namespace std;

int Solution::romanToInt(string s){
    vector<int> outBase = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> base = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int index = 0;
    int result = 0;
    while (index < base.size()){
        string a(1, s[0]);
        string b = "";
        if (s.size() > 1){
            b = s[1];
        }
        if (a == base[index]){
            result += outBase[index];
            s.erase(s.begin());
        }
        else if(a + b == base[index]){
            result += outBase[index];
            s.erase(s.begin());
            s.erase(s.begin());
        }
        else{
            index ++;
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    Solution sol;
    cout << sol.romanToInt(argv[1]) << endl;
    return 0;
}