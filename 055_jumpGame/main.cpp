#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
// right to left
// bool Solution::canJump(vector<int>& nums){
//    int reach = nums.size() - 1;
//    for (int i = nums.size() - 1; i >= 0; i--){
//       if (i + nums[i] >= reach) reach = i;
//    }
//    return reach == 0;
// }

bool Solution::canJump(vector<int>& nums){
   int reach = 0;
   for (int i = 0; i < nums.size(); i++){
      if (i > reach) return false;
      if (i + nums[i] >= reach) reach = i + nums[i];
      if (reach >= nums.size() - 1) return true;
   }
   return true;
}


int main(int argc, char* argv[]){
   Solution sol;
   vector<int> nums = {2, 0, 0, 0};
   cout << sol.canJump(nums) << endl;

}