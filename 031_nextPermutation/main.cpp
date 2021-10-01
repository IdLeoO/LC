#include "main.hpp"
#include <iostream>

using namespace std;

void Solution::nextPermutation(vector<int>& nums){
    
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