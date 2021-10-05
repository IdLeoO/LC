#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Solution::longestValidParentheses(string s){
    if (s == ""){
        return 0;
    }
    unordered_map<char, int> map;
    map['('] = 0;
    int maxcnt = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            map['('] ++;
        }
        else if (s[i] == ')' && map['('] > 0){
            map['('] --;
            cnt ++;
        }
        else{
            maxcnt = max(cnt, maxcnt);
            cnt = 0;
        }
    }
    if (map['('] == 0){
        maxcnt = max(cnt, maxcnt);
    }
    return 2* maxcnt;
}

int main(int argc, char* argv[]){
    Solution sol;
    string s = "(()";
    cout << sol.longestValidParentheses(s) <<endl;
    return 0;
}