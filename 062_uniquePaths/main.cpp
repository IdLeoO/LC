#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Solution::uniquePaths(int m, int n){
   if (m == 1 || n == 1){
      return 1;
   }
   vector<vector<int>> dp(m, vector<int> (n));
   for (int i = 0; i < m; i++){
      dp[i][0] = 1;
   }
   for (int j = 0; j < n; j++){
      dp[0][j] = 1;
   }
   for (int i = 1; i < m; i++){
      for (int j = 1; j < n; j++){
         dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
   }
   return dp[m-1][n-1];
} 
int main(int argc, char* argv[]){
   Solution sol;
   cout << sol.uniquePaths(3,7) << endl;

}