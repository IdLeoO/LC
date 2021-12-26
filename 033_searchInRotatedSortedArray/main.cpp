#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int Solution::search(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1, m = l + (r - l) / 2;
    while (l < r){ 
        if (nums[m] >= nums[l]){
            if (target > nums[m] || target < nums[l]){
                l = m + 1;
                m = l + (r - l) / 2;
            }
            else if (target < nums[m] && target > nums[l]){
                r = m - 1;
                m = l + (r - l) / 2;
            }
            else {
                if (target == nums[l]){
                    return l;
                }
                else if (target == nums[r]){
                    return r;
                }
                else if (target == nums[m]){
                    return m;
                }
                else{
                    throw("Error in m > l");
                }
            }
        }
        else {
            if (target < nums[m] || target > nums[r]){
                r = m;
                m = l + (r - l) / 2;
            }
            else if (target > nums[m] && target < nums[r]){
                l = m;
                m = l + (r - l) / 2;
            }
            else {
                if (target == nums[l]){
                    return l;
                }
                else if (target == nums[r]){
                    return r;
                }
                else if (target == nums[m]){
                    return m;
                }
                else{
                    throw("Error in m < r");
                }
            }
        }
    }

    if (l == r){
        if (nums[l] == target){
            return l;
        }
    }
    return -1;
}

int main(int argc, char* argv[]){
    vector <int> nums = {5,7, 1, 3, 4};
    Solution sol;
    cout << sol.search(nums, 4) << endl;
}