#include "main.hpp"
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> Solution::threeSum(vector<int>& nums){
    unordered_map<int, int> hash;
    vector<vector<int>> result = {};
    sort(nums.begin(), nums.end());
    if (nums.size() < 3){
        return result;
    }
    // Sort the numbers to find the last position of the repeating numbers.
    // Update the hash table to the last position of the repeating numbers.
    // Eliminating the repeating combination is the key point of this problem.
    for (int i = 0; i < nums.size(); i++){
        pair<int, int> inPair(nums[i], i);
        if (hash.find(nums[i]) != hash.end()){
            hash[nums[i]] = i;
            continue;
        }
        hash.insert(inPair);
    }
    for (int i = 0; i < nums.size() - 2; i++){
        if (i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        // If the current number is the same as the formal one, then the
        // result will be the same, so skip it for this loop.
        int sum1 = 0 - nums[i];
        for (int j = i + 1; j < nums.size() - 1; j++){
            if ( j > i + 1 && nums[j] == nums[j-1]){
                continue;
            }
            // Same for the inner loop.
            int sum2 = sum1 - nums[j];
            if (hash.find(sum2) != hash.end()){
                if (hash.find(sum2)->second <= j){
                    continue;
                }
                // Force the last target number be the last in original order.
                int target = hash.find(sum2)->first;
                vector<int> out;
                out.push_back(nums[i]);
                out.push_back(nums[j]);
                out.push_back(hash.find(sum2)->first);
                result.push_back(out);
            }
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    Solution sol;
    vector<int> input;
    // input.push_back(-1);
    // input.push_back(0);
    // input.push_back(1);
    // input.push_back(2);
    // input.push_back(-1);
    // input.push_back(-4); 
    input = {0, 0, 0, 0};
    vector<vector<int>> out = sol.threeSum(input);
    for (int i = 0; i < out.size(); i++){
        for (int j = 0; j < out[i].size(); j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
        
    }
    return 0;
}