#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> Solution::generateMatrix(int n){
   int num = 1, rb = 0, re = n - 1, cb = 0, ce = n - 1;
   vector<vector<int>> res(n, vector<int>(n));
   while (rb <= re && cb <= ce){
      for (int j = cb; j <= ce; j++){
         res[rb][j] = num++;
      }
      rb ++;
      for (int i = rb; i <= re; i++){
         res[i][ce] = num++;
      }
      ce --;
      for (int j = ce; j >= cb; j--){
         res[re][j] = num++;
      }
      re --;
      for (int i = re; i >= rb; i--){
         res[i][cb] = num++;
      }
      cb ++;
   }
   return res;
}
int main(int argc, char* argv[]){
   Solution sol;
   auto res = sol.generateMatrix(3);
   for (vector<int> &x: res){
      for(auto &i: x){
         cout << i << ' ';
      }
      cout << endl;
   }
}