#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int Solution::maxProfit(int k, vector<int>& prices){
   vector<int> s;
   s.push_back(0);
   for (int i = 0; i < 2 * k; i++){
      s.push_back(INT_MIN);
   }
   for (int i = 0; i < prices.size(); i++){
      for (int j = 1; j <= k; j++){
         s[2*j - 1] = max(s[2*j - 1], s[2*j - 2] - prices[i]);
         s[2*j] = max(s[2*j], s[2*j - 1] + prices[i]);
      }
   }
   
   return max(0, s[2*k]);
}
int main(int argc, char* argv[]){
   Solution sol;
   vector<int> prices = {2,6,8,7,8,7,9,4,1,2,4,5,8};
   cout << sol.maxProfit(3, prices) << endl;
}