#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int Solution::maxProfit(vector<int>& prices){
   int maxP = 0;
   for (int i = 1; i < prices.size(); i++){
      maxP += ((prices[i] - prices[i-1]) > 0)? prices[i] - prices[i-1]: 0;
   }
   return maxP;
}
int main(int argc, char* argv[]){
   Solution sol;
   //vector<int> prices = {7,1,5,3,6,4};
   vector<int> prices = {5,4,2,1};
   cout << sol.maxProfit(prices) << endl;

}