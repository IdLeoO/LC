#include "main.hpp"
#include <iostream>
using namespace std;

string Solution::longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    string tmp = "";
    for (int i = 1; i < strs.size(); i++){
        for (int j = 0; j < strs[i].size(); j++){
            if (strs[i][j] == prefix[j]){
                tmp += strs[i][j];
            }
            else{
                break;                
            }
        }
        if (prefix == ""){
            return prefix;
        }
        prefix = tmp;
        tmp = "";
    }
    return prefix;
}

int main(int argc, char* argv[]){
    Solution sol;
    vector<string> input;
    input.push_back("flower");
    input.push_back("flow");
    input.push_back("flight");
    cout << sol.longestCommonPrefix(input) << endl;
}

