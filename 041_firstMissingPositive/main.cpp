#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int Solution::firstMissingPositive(vector<int>& nums){
    for (int i = 0; i < nums.size(); i ++){
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]){
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    int result = 1;
    for (int i = 0; i < nums.size();i++){
        //cout << nums[i] << " " << i + 1<< endl;
        if (nums[i] != i + 1){
            result = i + 1;
            break; 
        }
        if (i == nums.size() - 1){
            result = i + 2;
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    Solution sol;
    vector<int> nums = {1, 2, 0};
    cout << sol.firstMissingPositive(nums) << endl;

    
}