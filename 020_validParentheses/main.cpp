#include "main.hpp"
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool Solution::isValid(string s){
    unordered_map<char, int> left;
    unordered_map<char, int> right;
    stack<char> storage;
    left.insert({'(', 1});
    left.insert({'[', 2});
    left.insert({'{', 3});
    right.insert({')', 1});
    right.insert({']', 2});
    right.insert({'}', 3});
    for (int i = 0; i < s.size(); i++){
        char tmp = s[i];
        if (left.find(tmp) != left.end()){
           storage.push(tmp); 
           continue;
        }
        if (right.find(tmp) != right.end()){
            if (storage.empty()){
                return false;
            }
            char prev = storage.top();
            if (left.find(prev) != left.end()){
                if (left[prev] == right[tmp]){
                    storage.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    if (!storage.empty()){
        return false;
    }
    return true;
}

int main(int argc, char* argv[]){
    string input1("]");
    string input2("]");
    string input3("{[]}");  
    Solution sol;
    cout << sol.isValid(input1)<<endl;
    cout << sol.isValid(input2)<<endl;
    cout << sol.isValid(input3)<<endl;
    return 0;
}