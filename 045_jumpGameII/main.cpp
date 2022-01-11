#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
// assume always can reach last
int Solution::jump(vector<int> &nums){
   int maxD = 0, tmp = 0;
   int hop = 0;
   for (int i = 0; i < nums.size() - 1; i++){
      nums[i] += i;
      tmp = max(tmp, nums[i]);
      if (maxD == i){
         maxD = tmp;
         hop ++;
         if (maxD >= nums.size() - 1) break;
      }
   }
   // for (auto &x: nums){
   //    cout << x << ' ';
   // }
   // cout << endl;
   return hop;
}

int main(int argc, char* argv[]){
   Solution sol;
   vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
   cout << sol.jump(nums) << endl;
}