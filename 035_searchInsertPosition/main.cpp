#include "main.hpp"
#include <iostream>
using namespace std;


int Solution::searchInsert(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1, m;
    while (l <= r){
        m = l + (r - l) / 2;
        if (nums[m] < target){
            l = m + 1;
        }
        else {
            if (m == 0 || nums[m - 1] < target ){
                return m;
            }
            r = m - 1;
        }
    }
    return nums.size();
}

int main(int argc, char* argv[]){
    vector<int> nums = {3,5,6};
    Solution sol;
    cout << sol.searchInsert(nums, 7) << endl;
}