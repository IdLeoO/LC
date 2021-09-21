#ifndef MAIN
#define MAIN

#include <vector>
#include <string>
class Solution{
    public:
    std::vector<std::string> generateParenthesis(int n);
    void dfs(std::string output, int leftNum, int rightNum, std::vector<std::string> &result);
};

#endif