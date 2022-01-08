#ifndef MAIN
#define MAIN
#include <string>

class Solution{
    public:
    bool dfs(int **dp, std::string &s, std::string &p,int i, int j);
    bool isMatch(std::string s, std::string p);
};

#endif