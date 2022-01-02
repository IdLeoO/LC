#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void Solution::DFS(vector<int>& candidates, int target, int idx, vector<vector<int>> &result, vector<int> &comb){
    if (target < 0){
        return;
    }
    if (target == 0){
        result.push_back(comb);
        return;
    }
    
    for (int i = idx; i < candidates.size(); i++){
        comb.push_back(candidates[i]);
        DFS(candidates, target - candidates[i], i, result, comb);
        comb.pop_back();
    }
}
vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> comb;
    DFS(candidates, target, 0, result, comb);
    return result;
}

int main(int argc, char* argvp[]){
    Solution sol;
    vector<int> candidates = {2};
    auto result = sol.combinationSum(candidates, 2);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

