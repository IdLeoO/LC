#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
void dfs(vector<int>& remain, vector<vector<int>> & res, vector<int> &p){
   if (remain.empty()){
      res.push_back(p);
      return;
   }
   int last = remain[0];
   for (int i = 0; i < remain.size(); i++){
      if (i > 0 && last == remain[i]) continue;
      int tmp = remain[i];
      remain.erase(remain.begin() + i);
      p.push_back(tmp);
      dfs(remain, res, p);
      p.pop_back();
      remain.insert(remain.begin() + i, tmp);
      last = tmp;
   }
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums){
   vector<vector<int>> res;
   vector<int> p;
   sort(nums.begin(), nums.end());
   dfs(nums, res, p);
   return res;
}

int main(int argc, char* argv[]){
   vector<int> nums = {1,1,2,2};
   Solution sol;
   for (vector<int> &x: sol.permuteUnique(nums)){
      for (auto &i: x){
         cout << i << ' ';
      }
      cout << endl;
   }
}