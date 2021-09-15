#include "main.hpp"
#include <algorithm>
#include <iostream>

using namespace std;
/*
Increasing the sum means that the difference between the sum and the 
target will go lager, and decreasing the sum makes it smaller. When the 
differential is <0, we would like to decrease the sum to make it closer
to 0. When the differential is >0, the sum is to be increased.

The assignment of residue locates better right after the diff by a judgement.

*/
int Solution::threeSumClosest(vector<int>& nums, int target){
    if (nums.size() < 3){
        return 0;
    }
    int res = INT32_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() -2; i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        
        int start = i + 1;
        int end = nums.size() - 1;
        int diff;
        while (start < end){
            diff = target - nums[i];
            diff -= nums[start] + nums[end];
            if (abs(res) > abs(diff)){
                res = diff;
            }
            if (diff < 0){
                end --;
            }
            else if(diff > 0){
                start ++;
            }
            else{
                return target;
            }
        }  
    }
    return target-res;
}

int main(int argc, char* argv[]){
    vector<int> input = {1, 2, 5, 10, 11};
    int target = 12;
    Solution sol;
    int result = sol.threeSumClosest(input, target);
    cout << result << endl;
    return 0;
}