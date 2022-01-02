#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// string Solution::countAndSay(int n){
//     if (n == 1){
//         return "1";
//     }
//     stack<int> seq;
//     seq.push(1);
//     for (int i = 1; i < n; i++){
//         stack<int> tmp;
//         while (!seq.empty()){
//             int top = seq.top();
//             int cntTop = 0;
//             while (!seq.empty() && seq.top() == top){
//                 seq.pop();
//                 cntTop++;
//             }
//             tmp.push(top);
//             tmp.push(cntTop);
//         }
//         while (!tmp.empty()){
//             seq.push(tmp.top());
//             tmp.pop();
//         }
//     }
//     string result = "";
//     while (!seq.empty()){
//         result.insert(0, to_string(seq.top()));
//         seq.pop();
//     }
//     return result;
// }


string Solution::countAndSay(int n){
    if (n == 1){
        return "1";
    }
    string seq = "1";
    for (int i = 1; i < n; i++){
        string tmp;
        auto idx = seq.begin();
        while (idx != seq.end()){
            auto front = *idx;
            int cnt = 0;
            while (*idx == front){
                idx ++;
                cnt ++;
            }
            tmp += to_string(cnt) + front;
        }
        seq = tmp;
    }
    return seq;
}

int main(int argc, char* argv[]){
    Solution sol;
    cout << sol.countAndSay(10) << endl;
}