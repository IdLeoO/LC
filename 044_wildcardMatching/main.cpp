#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool Solution::dfs(int **dp, string &s, string &p, int i, int j){
   if (dp[i][j] == 2){
      if (s[i] == '*'){
         for (int ip = i; ip < s.size(); ip++){
            if (dfs(dp, s, p, i, ip)){
               return true;
            }

         }
         
      }
   }
}

bool Solution::isMatch(string s, string p){
   s = " " + s + " ";
   p = " " + p + " ";

   int **dp = new int *[s.size()];
   for (int i = 0; i < s.size(); i ++){
      dp[i] = new int[p.size()];
   }
   // int dp2[s.size()][p.size()];
   for (int i = 0; i < s.size(); i ++){
      for (int j = 0; j < p.size(); j ++){
         if ((s[i] == '*') || (p[j] == '*')) dp[i][j] = 2;
         else if (s[i] == p[j] || s[i] == '?' || p[j] == '?') dp[i][j] = 1;
         else dp[i][j] = 0;
      }
   }

   for (int i = 0; i < s.size(); i ++){
      for (int j = 0; j < p.size(); j ++){
         cout << dp[i][j] << ' ';
      }
      cout << endl;
   }

   int is = 0, ip = 0;
   return dfs(dp, is, ip);




   // while (is != s.size() || ip != p.size()){
   //    if (dp[is][ip] >= 1){
   //       if (is == s.size() - 1 && ip == p.size() - 1){
   //          return true;
   //       }
   //       if (is == s.size() - 1){
   //          if (s[is] == '*') return true;
   //          if ((is >= 1 && s[is - 1] == '*') || (is >= 2 && s[is - 2] == '*')){
   //             is --;
   //             continue;
   //          }
   //          else{
   //             return false;
   //          }
   //       }
   //       if (ip == p.size() - 1){
   //          if (p[ip] == '*') return true;
   //          if ((ip >= 1 && p[ip - 1] == '*') || (ip >= 2 && p[ip - 2] == '*')){
   //             ip --;
   //             continue;
   //          }
   //          else{
   //             return false;
   //          }
   //       }
   //       is ++;
   //       ip ++;
   //    }
   //    else{
   //       if ((is >= 1 && s[is - 1] == '*') || (s[is] == '*')){
   //          ip ++;
   //          continue;
   //       }
   //       else if((ip >= 1 && p[ip - 1] == '*') || (p[ip] == '*')){
   //          is ++;
   //          continue;
   //       }
   //       else return false;
   //    }
   // }
   // return false;
}

int main(int argc, char* argv[]){
   Solution sol;
   string s = "*a", p = "*b*";
   cout << s << ' ' << p << endl;
   cout << sol.isMatch(s, p) << endl;
}