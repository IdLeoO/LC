#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
int Solution::maxProfit(vector<int>& prices){
   int localMin = prices[0], gPrices = 0;
   for (int &x: prices){
      localMin = min(x, localMin);
      gPrices = max(gPrices, x - localMin);
   }
   return gPrices;
}

int main(int argc, char* argv[]){
   Solution sol;
   vector<int> prices = {2, 4, 1};
   cout << sol.maxProfit(prices) << endl;

}