#include "main.hpp"
#include <iostream>

using namespace std;

void Solution::nextPermutation(vector<int>& nums){
    bool np = false;
    int partition = 0;
    int change = 0;
    for (int i = nums.size() - 1; i > 0; i--){
        if (nums[i] > nums[i -1 ]){
            partition = i - 1;
            np = true;
            break;
        }
    }
    if (!np){
        for (int i = 0; i <= (nums.size() - 1)/2; i++){
            int tmp = nums[i];
            nums[i] = nums[nums.size() - 1 - i];
            nums[nums.size() - 1 - i] = tmp; 
        }
    }
    else{
        for (int i = nums.size() - 1; i > 0; i--){
            if (nums[i] > nums[partition]){
                change = i;
                int tmp = nums[i];
                nums[i] = nums[partition];
                nums[partition] = tmp;
                break;
            }
        }
        for (int i = partition + 1; i <= (partition + nums.size() ) / 2; i++){
            int tmp = nums[i];
            nums[i] = nums[nums.size() - i + partition];
            nums[nums.size() - i + partition] = tmp; 
        }
    }
}

int main(int argc, char* argv[]){
    Solution sol;
    vector<int> nums = {1,3,2};
    sol.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}