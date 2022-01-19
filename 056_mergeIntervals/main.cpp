#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
   if (a[0] == b[0]) return a[1] < b[1];
   else return a[0] < b[0];
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals){
   sort(intervals.begin(), intervals.end(), cmp);
   vector<vector<int>> res;
   res.push_back(intervals[0]);
   for (int i = 1; i < intervals.size(); i++){
      if (res[res.size() - 1][1] < intervals[i][0]) res.push_back(intervals[i]);
      else res[res.size() - 1][1] = max(intervals[i][1], res[res.size() - 1][1]);
   }
   return res;
}
int main(int argc, char* argv[]){
   Solution sol;

}