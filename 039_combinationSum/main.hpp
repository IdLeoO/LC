#ifndef MAIN
#define MAIN

#include <vector>

class Solution{
    public:
    void DFS(std::vector<int>& candidates, int target, int idx, std::vector<std::vector<int>>& result, std::vector<int>& comb);
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
};

#endif