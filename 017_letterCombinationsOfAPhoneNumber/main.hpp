#ifndef MAIN
#define MAIN
#include <vector>
#include <string>
class Solution{
    public:
    std::vector<std::string> letterCombinations(std::string digits);
    void DFS(std::vector<std::vector<std::string>> &keys, int layer, std::vector<std::string> &result, std::string output);
};

#endif
