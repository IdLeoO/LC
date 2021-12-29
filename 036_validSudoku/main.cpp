#include "main.hpp"
#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;

bool Solution::isValidSudoku(vector<vector<char>>& board) {
    unordered_set<int> row[9];
    unordered_set<int> col[9];
    unordered_set<int> box[9];
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == '.'){
                continue;
            }
            int digit = int(board[i][j]);
            int rowIdx = i;
            int colIdx = j;
            int boxIdx = i/3*3 + j/3;
            if (row[rowIdx].find(digit) != row[rowIdx].end() || col[colIdx].find(digit) != col[colIdx].end() || box[boxIdx].find(digit) != box[boxIdx].end()){
                return false;
            }
            row[rowIdx].insert(digit);
            col[colIdx].insert(digit);
            box[boxIdx].insert(digit);
        }
    }
    return true;
}

int main(int argc, char* argv[]){
    char board[9][9] = {{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution sol;
    cout << sol.isValidSudoku(board) << endl;
}