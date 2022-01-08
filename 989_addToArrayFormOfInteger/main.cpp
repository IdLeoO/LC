#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> Solution::addToArrayForm(vector<int>& num,int k){
   int i = num.size() - 1;
   while (k != 0 ){
      int dgt = (i >= 0 ) ? num[i] + k : k;
      k = dgt / 10;
      if (i >= 0){
         num[i] = dgt % 10;
      }
      else{
         num.insert(num.begin(), dgt % 10);
      }
      i--;
   }
   return num;
}

int main(int argc, char* argv[]){
   Solution sol;
   vector<int> num = {999};
   int k = 1;
   auto res = sol.addToArrayForm(num, k);
   for(auto &x: res){
      cout << x;
   }
   cout << endl;
}