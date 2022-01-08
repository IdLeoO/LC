#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string Solution::multiply(string num1, string num2){
    if (num1 == "0" || num2 == "0") return "0";
    int i1 = num1.size() - 1, i2 = num2.size() - 1;
    vector<int> res(num1.size() + num2.size(), 0);
    for (int i = i1; i >= 0; i--){
        for (int j = i2; j >= 0; j--){
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }
    string ans = "";
    int idx = 0;
    while (res[idx] == 0) idx++;
    while (idx <= res.size() - 1){
        ans += to_string(res[idx]);
        idx++;
    }
    return ans;
}

int main(int argc, char* argv[]){
    Solution sol;
    string num1 = "123", num2 = "456";
    cout << sol.multiply(num1, num2) << endl;
}