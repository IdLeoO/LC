#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// dp solution
int Solution::maxProfit(vector<int>& prices){
   vector<int> lmaxP = {0}, rmaxP = {0};
   bool flag = false;
   int lMin = prices[0], rMax = prices[prices.size() - 1];
   for (int i = 1; i < prices.size(); i++){
      lMin = min(lMin, prices[i]);
      lmaxP.push_back(max(prices[i] - lMin, lmaxP[i - 1]));
   }

   for (int i = prices.size() - 2; i >= 0; i--){
      rMax = max(rMax, prices[i]);
      rmaxP.push_back(max(rMax - prices[i], rmaxP[prices.size() - 2 - i]));
   }
   reverse(rmaxP.begin(), rmaxP.end());
   int res = 0;
   for (int i = 0; i < rmaxP.size(); i ++){
      res = max(res, rmaxP[i] + lmaxP[i]);
   }
   return res;
}

// FSM solution
int Solution::maxProfit(vector<int>& prices){
   if (prices.empty()) return 0;
   int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
   for (int i = 0; i < prices.size(); i++){
      s1 = max(s1, -prices[i]);
      s2 = max(s2, s1 + prices[i]);
      s3 = max(s3, s2 - prices[i]);
      s4 = max(s4, s3 + prices[i]);
   }
   return max(0, s4);
}

int main(int argc, char* argv[]){
   Solution sol;
   vector<int> prices = {3,2,1};
   for (auto &x: prices){
      cout << x <<' ';
   }
   cout << endl;
   cout << sol.maxProfit(prices) << endl;
}