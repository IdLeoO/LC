#ifndef MAIN
#define MAIN

#include <vector>

class Solution{
    public:
    bool DFS(std::vector<std::vector<char>>& board, int i, int j);
    bool isValidSudoku(std::vector<std::vector<char>>& board, int i, int j, char a);
    void solveSudoku(std::vector<std::vector<char>>& board);
};

#endif