#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& grid,int state, int x, int y, int &cnt){
   // for (vector<int> &x:grid){
   //    for (int &i : x){
   //       cout << i << ' ';
   //    }
   //    cout << endl;
   // }
   // cout << endl;
   if (state == 2){
      vector<vector<int>> ref(grid.size(),vector<int> (grid[0].size(), -1));
      if (grid == ref) {
         cnt ++;
      }
      return;
   }
   if (x + 1 < grid.size() && grid[x+1][y] != -1){
      int state = grid[x+1][y];
      grid[x+1][y] = -1;
      dfs(grid, state, x + 1, y, cnt);
      grid[x+1][y] = state;
   }
   if (x - 1 >= 0 && grid[x-1][y] != -1){
      int state = grid[x-1][y];
      grid[x-1][y] = -1;
      dfs(grid, state, x - 1, y, cnt);
      grid[x-1][y] = state;
   }
   if (y + 1 < grid[0].size() && grid[x][y+1] != -1){
      int state = grid[x][y+1];
      grid[x][y+1] = -1;
      dfs(grid, state, x, y+1, cnt);
      grid[x][y+1] = state;
   }
   if (y - 1 >= 0 && grid[x][y-1] != -1){
      int state = grid[x][y-1];
      grid[x][y-1] = -1;
      dfs(grid, state, x, y-1, cnt);
      grid[x][y-1] = state;
   }
}

int Solution::uniquePathsIII(vector<vector<int>>& grid){
   int cnt = 0;
   for (int i = 0; i < grid.size(); i++){
      for (int j = 0; j < grid[0].size(); j++){
         if (grid[i][j] == 1){
            grid[i][j] = -1;
            dfs(grid, 1, i, j, cnt);
            return cnt;
         }
      }
   }
   return 0;
}

int main(int argc, char* argv[]){
   Solution sol;
   vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
   cout << sol.uniquePathsIII(grid) << endl;
}