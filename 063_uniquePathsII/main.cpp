#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
   int m = obstacleGrid.size(), n = obstacleGrid[0].size();
   vector<vector<int>> dp(m, vector<int> (n));
   dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
   for (int i = 1; i < m; i++){
      dp[i][0] = (obstacleGrid[i][0] == 0) ? dp[i-1][0] : 0;
   }
   for (int j = 1; j < n; j++){
      dp[0][j] = (obstacleGrid[0][j] == 0) ? dp[0][j-1] : 0;
   }
   for (int i = 1; i < m; i++){
      for (int j = 1; j < n; j++){
         dp[i][j] = (obstacleGrid[i][j] == 0) ? dp[i-1][j] + dp[i][j-1] : 0;
      }
   }
   for (vector<int> &i: dp){
      for (int &x: i){
         cout << x << ' ';
      }
      cout << endl;
   }
   return dp[m-1][n-1];
}
int main(int argc, char* argv[]){
   Solution sol;
   vector<vector<int>> num = {{0,1,0}};
   cout << sol.uniquePathsWithObstacles(num)<< endl;

}