#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool checkValid(vector<vector<int>> &board, int rowId, int colId){
   for (int i = 0; i < rowId; i++){
      if (board[i][colId]) return false;
   }
   for (int i = rowId - 1, j = colId - 1; i >= 0 && j >= 0; i--, j--){
      if (board[i][j]) return false;
   }
   for (int i = rowId - 1, j = colId + 1; i >= 0 && j < board.size(); i--, j++){
      if (board[i][j]) return false;
   }
   return true;
}

void dfs(vector<vector<int>> &board, int &res, int i){
   string rowStr;
   for (int j = 0; j < board.size(); j ++){
      board[i][j] = 1;
      if (checkValid(board, i, j)){
         if (i == board.size() - 1){
            res ++;
         }
         else{
            dfs(board, res, i + 1);
         }
      }
      board[i][j] = 0;
   }
}
int Solution::totalNQueens(int n){
   vector<vector<int>> board(n, vector<int>(n, 0));
   int res = 0;
   dfs(board, res, 0);
   return res;
}
int main(int argc, char* argv[]){
   Solution sol;
   cout << sol.totalNQueens(4) << endl;

}