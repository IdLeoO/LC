#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int Solution::maxSubArray(vector<int>& nums){
   int sum = 0;
   int gMax = INT_MIN;
   for (int &x: nums){
      sum = max(sum + x, x);
      gMax = max(gMax, sum);
   }
   return gMax;
}
int main(int argc, char* argv[]){
   Solution sol;
   vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
   cout << sol.maxSubArray(nums) << endl;

}