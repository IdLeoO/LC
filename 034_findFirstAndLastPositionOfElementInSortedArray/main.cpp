#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> Solution::searchRange(vector<int> & nums, int target){
    int l = 0, r = nums.size() - 1, lm, rm;
    vector<int> result = {-1, -1};
    while (l <= r){
        lm = l + (r - l)/2;
        if (nums[lm] < target){
            l = lm + 1;
        }
        else if (nums[lm] > target){
            r = lm - 1;
        }
        else{
            if (lm == 0 || nums[lm - 1] != nums[lm]){
                result[0] = lm;
                break;
            }
            r = lm - 1;
        }
    }
    l = 0, r = nums.size() - 1;
    while (l <= r){
        rm = l + (r - l)/2;
        if (nums[rm] < target){
            l = rm + 1;
        }
        else if (nums[rm] > target){
            r = rm - 1;
        }
        else{
            if (rm == nums.size() - 1 || nums[rm + 1] != nums[rm]){
                result[1] = rm;
                break;
            }
            l = rm + 1;
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    vector<int> nums = {1, 1};
    Solution sol;
    vector<int> result = sol.searchRange(nums, 1);
    for (int i = 0; i < result.size(); i++){
        cout <<  result[i];
    }
    cout << endl;
    
}