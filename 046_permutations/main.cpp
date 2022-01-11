#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<int>& remain, vector<vector<int>> & res, vector<int> &p){
   if (remain.empty()){
      res.push_back(p);
      return;
   }
   for (int i = 0; i < remain.size(); i++){
      int tmp = remain[i];
      remain.erase(remain.begin() + i);
      p.push_back(tmp);
      dfs(remain, res, p);
      p.pop_back();
      remain.insert(remain.begin() + i, tmp);
   }
}
vector<vector<int>> Solution::permute(vector<int>& nums){
   vector<vector<int>> res;
   vector<int> p;
   dfs(nums, res, p);
   return res;
}

int main(int argc, char* argv[]){
   Solution sol;
   vector<int> nums = {1,2,3};
   for (vector<int> &x: sol.permute(nums)){
      for (auto &i: x){
         cout << i << ' ';
      }
      cout << endl;
   }
}