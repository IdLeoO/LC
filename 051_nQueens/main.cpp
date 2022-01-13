#include "main.hpp"
#include <iostream>
#include <algorithm>

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

void dfs(vector<vector<int>> &board, vector<vector<string>> &res, vector<string> &tmp, int i){
   string rowStr;
   for (int j = 0; j < board.size(); j++){
      rowStr += ".";
   }
   for (int j = 0; j < board.size(); j ++){
      board[i][j] = 1;
      if (checkValid(board, i, j)){
         rowStr[j] = 'Q';
         tmp.push_back(rowStr);
         if (i == board.size() - 1){
            res.push_back(tmp);
         }
         else{
            dfs(board, res, tmp, i + 1);
         }
         tmp.pop_back();
         rowStr[j] = '.';
      }
      board[i][j] = 0;
   }
}
vector<vector<string>> Solution::solveNQueens(int n){
   vector<vector<int>> board(n, vector<int>(n, 0));
   vector<string> tmp;
   vector<vector<string>> res;
   dfs(board, res, tmp, 0);
   return res;
}

int main(int argc, char* argv[]){
   Solution sol;
   for (vector<string> &x: sol.solveNQueens(4)){
      for (auto &i: x){
         cout << i << endl;
      }
      cout << endl;
   }
}