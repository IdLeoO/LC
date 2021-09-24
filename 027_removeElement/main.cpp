#include "main.hpp"
#include <iostream>
using namespace std;

int Solution::removeElement(vector<int>& nums, int val){
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] != val){
            nums[i - cnt] = nums[i];
        }
        else{
            cnt ++;
        }
    }
    return nums.size() - cnt;
}

int main(int argc, char* argv[]){
    vector<int> input = {1,2,3,3,0,1,2,3,2,3};
    Solution sol;
    int num = sol.removeElement(input, 2);
    for (int i = 0; i < num; i++){
        cout << input[i];
    }
    cout << endl;
}

