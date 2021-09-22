#include "main.hpp"
#include <iostream>

using namespace std;

int Solution::removeDuplicates(vector<int>& nums){
    switch (nums.size()){
        case 0: return 0;
        case 1: return 1;
        default:;
    }
    int slow = 1, fast = 1;
    while(fast < nums.size()){
        if (nums[fast] > nums[slow - 1]){
            nums[slow] = nums[fast];
            slow ++;
            fast ++;
        }
        else{
            fast ++;
        }
    }
    return slow;
}

int main(int argc, char* argv[]){
    Solution sol;
    vector<int> input = {0,0,1,1,1,2,2,3,3,4};
    int result = sol.removeDuplicates(input);
    for (int i = 0; i < result; i++){
        cout << input[i] << " ";
    }
    cout << endl;
}