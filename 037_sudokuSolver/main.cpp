#include "main.hpp"
#include <iostream>

using namespace std;
bool Solution::isValidSudoku(vector<vector<char>>& board, int i, int j, char a) {
    for (int k = 0; k < 9; k++){
        if (board[i][k] == a){
            return false;
        }
        if (board[k][j] == a){
            return false;
        }
        if (board[i-i%3+k/3][j-j%3+k%3] == a){
            return false;
        }
    }
    return true;
}

bool Solution::DFS(vector<vector<char>>& board, int i, int j){
    if (i == 9) return true;
    if (j == 9) return DFS(board, i + 1, 0);

    if (board[i][j] == '.'){
        for (char a = '1'; a <= '9'; a++){
            if (isValidSudoku(board, i, j, a)){
                board[i][j] = a;
                if (DFS(board, i, j + 1)){
                    return true;
                }
                board[i][j] = '.';
            }
        }
    }
    else {
        return DFS(board, i, j + 1);
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char>>& board){
    DFS(board, 0, 0);
}

int main(int argc, char* argv[]){



}

