#include "main.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target){
    vector<vector<int>> result;
    unordered_map<int, int> hash;
    if (nums.size() < 4){
        return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++){
        auto hashPair = make_pair(target - nums[i], i);
        if (hash.find(target - nums[i]) != hash.end()){
            hash[target - nums[i]] = i;
        }
        else{
            hash.insert(hashPair);
        }
    }
    for (int i = 0; i < nums.size() - 3; i++){ 
        if (i > 0 && nums[i] == nums[i -1 ]){
            continue;
        }
        for (int j = i + 1; j < nums.size() - 2; j++){
            if (j > i + 1 && nums[j] == nums[j -1 ]){
                continue;
            }
            for (int k = j + 1; k < nums.size() - 1; k++){
                if (k > j + 1 && nums[k] == nums[k - 1]){
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                // This addition is likely to cause integer overflow
                // Better to use the long and add in steps
                if (hash.find(sum) != hash.end() && hash[sum] > k){
                    vector<int> partResult;
                    partResult.push_back(nums[i]);
                    partResult.push_back(nums[j]);
                    partResult.push_back(nums[k]);
                    partResult.push_back(target - sum);
                    result.push_back(partResult);
                }
            }
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    vector<int> input = {1000000000, 1000000000, 1000000000, 1000000000};
    int target = 0;
    Solution sol;
    auto result = sol.fourSum(input, target);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}