#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval){
   intervals.push_back(newInterval);
   sort(intervals.begin(), intervals.end());
   vector<vector<int>> res;
   res.push_back(intervals[0]);
   for (int i = 1; i < intervals.size(); i++){
      if (res[res.size() - 1][1] >= intervals[i][0]){
         res[res.size() - 1][1] = max(intervals[i][1], res[res.size() - 1][1]); 
      }
      else{
         res.push_back(intervals[i]);
      }
   }
   return res;
}

int main(int argc, char* argv[]){
   Solution sol;
   vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
   vector<int> newInterval = {4,8};
   vector<vector<int>> s = sol.insert(intervals, newInterval);
   for (vector<int> &x: s){
      for (int &i:x){
         cout << i << ' ';
      }
      cout << endl;
   }
}