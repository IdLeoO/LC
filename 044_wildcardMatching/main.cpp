#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// O(n^2) not efficient, DP and dfs
// bool Solution::dfs(int **dp, string &s, string &p, int i, int j){
//    // cout << i << ' ' << j << endl;
//    if (dp[i][j] == 2){
//       if (i == s.size() - 1 && j == p.size() - 1) return true;
//       if (i == s.size() - 1 && s[i] == '*') return true;
//       if (j == p.size() - 1 && p[j] == '*') return true;
//       if (s[i] == '*'){
//          for (int ip = j + 1; ip < p.size(); ip++){
//             if (dp[i + 1][ip] == 2 && s[i + 1] == '*'){
//                if (dfs(dp, s, p, i + 1, ip - 1)){
//                   return true;
//                }
//             }
//             if (dp[i + 1][ip] == 2 && p[ip] == '*'){
//                if (dfs(dp, s, p, i, ip)){
//                   return true;
//                }
//             }
//             if (dp[i + 1][ip] == 1 && dfs(dp, s, p, i + 1, ip)){
//                return true;
//             }
//          }
//       }
//       if (p[j] == '*'){
//          for (int is = i + 1; is < s.size(); is++){
//             if (dp[is][j + 1] == 2 && s[is] == '*'){
//                if (dfs(dp, s, p, is, j)){
//                   return true;
//                }
//             }
//             if (dp[is][j + 1] == 2 && p[j + 1] == '*'){
//                if (dfs(dp, s, p, is - 1, j + 1)){
//                   return true;
//                }
//             }
//             if (dp[is][j + 1] == 1 && dfs(dp, s, p, is, j + 1)){
//                return true;
//             }
//          }
//       }
//    }
//    if (dp[i][j] == 1){
//       if (i == s.size() - 1 && j == p.size() - 1) return true;
//       if (i == s.size() - 1 || j == p.size() - 1) return false;
//       if (dp[i + 1][j + 1] == 2 && s[i + 1] == '*'){
//          if (dfs(dp, s, p, i + 1, j)){
//             return true;
//          }
//       }
//       if (dp[i + 1][j + 1] == 2 && p[j + 1] == '*'){
//          if (dfs(dp, s, p, i, j + 1)){
//             return true;
//          }
//       }
//       if (dp[i + 1][j + 1] == 1 && dfs(dp, s, p, i + 1, j + 1)){
//          return true;
//       }
//    }
//    return false;
// }

// bool Solution::isMatch(string s, string p){
//    s = " " + s + " ";
//    p = " " + p + " ";
//    string snew;
//    string pnew;
//    auto slast = s[0], plast = s[0];
//    for (int i = 1; i < s.size(); i++){
//       if (s[i] == '*' && slast == '*'){
//          continue;
//       }
//       snew.push_back(s[i]);
//       slast = s[i];
//    }
//    snew = " " + snew;
//    for (int i = 1; i < p.size(); i++){
//       if (p[i] == '*' && plast == '*'){
//          continue;
//       }
//       pnew.push_back(p[i]);
//       plast = p[i];
//    }
//    pnew = " " + pnew;
//    int **dp = new int *[snew.size()];
//    for (int i = 0; i < snew.size(); i ++){
//       dp[i] = new int[pnew.size()];
//    }
//    // int dp2[s.size()][p.size()];
//    for (int i = 0; i < snew.size(); i ++){
//       for (int j = 0; j < pnew.size(); j ++){
//          if ((snew[i] == '*') || (pnew[j] == '*')) dp[i][j] = 2;
//          else if (snew[i] == pnew[j] || snew[i] == '?' || pnew[j] == '?') dp[i][j] = 1;
//          else dp[i][j] = 0;
//       }
//    }

//    for (int i = 0; i < snew.size(); i ++){
//       for (int j = 0; j < pnew.size(); j ++){
//          cout << dp[i][j] << ' ';
//       }
//       cout << endl;
//    }

//    int is = 0, ip = 0;
//    return dfs(dp, snew, pnew, is, ip);
// }


bool Solution::isMatch(string s, string p){
   vector<vector<bool>> dp(s.size() + 1, vector<bool> (p.size() + 1, false));
   dp[0][0] = true;
   for (int i = 0; i < p.size() && p[i] == '*'; i++){
      dp[0][i + 1] = true;
   }
   for (int i = 0; i < s.size(); i++){
      for (int j = 0; j < p.size(); j++){
         if (p[j] == '*'){
            dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
         }
         else {
            dp[i + 1][j + 1] = dp[i][j] && (s[i] == p[j] || p[j] == '?');
         }
      }   
   }
   return dp[s.size()][p.size()];
}

int main(int argc, char* argv[]){
   Solution sol;
   string s = "ab", p = "?*"
   cout << s << ' ' << p << endl;
   cout << sol.isMatch(s, p) << endl;
}