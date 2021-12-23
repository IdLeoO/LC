#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int Solution::longestValidParentheses(string s){
    vector<int> dp;
    int ans = 0;
    if (s.length() == 0){
        return ans;
    }
    stack<int> storage;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            storage.push(i);
            dp.push_back(0);
        }
        else{
            if (!storage.empty()){
                int left = storage.top();
                storage.pop();
                int len = i - left + 1;
                if (left != 0){
                    dp.push_back(dp[left-1] + len);
                }
                else{
                    dp.push_back(dp[left] + len);
                }
                ans = max(ans, dp[i]);
            }
            else {
                dp.push_back(0);
            }
        }
    }
    return ans;
}

// Counting the number of ( and ) while traversing the string. Traverse in reverse
// order later.
int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                left ++;
            }
            else{
                right ++;
            }
            if (left == right){
                ans = max(ans, 2 * left);
            }
            else if (right >= left){
                right = 0;
                left = 0;
            }
        }
        
        left = 0, right = 0;
        for (int i = s.length() - 1; i >= 0 ; i--){
            if (s[i] == '('){
                left ++;
            }
            else{
                right ++;
            }
            if (left == right){
                ans = max(ans, 2 * left);
            }
            else if (left >= right){
                right = 0;
                left = 0;
            }
        }
        return ans;
    }


int main(int argc, char* argv[]){
    Solution sol;
    string s = ")()()()((())))";
    cout << sol.longestValidParentheses(s) <<endl;
    return 0;
}