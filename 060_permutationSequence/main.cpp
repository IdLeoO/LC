#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string Solution::getPermutation(int n, int k){
   string res = "";
   vector<char> ref;
   long long factorial = 1, step = n;
   k--;
   while (step >= 1){
      factorial *= step--;
   }
   cout << factorial << endl;
   for (int i = 0; i < n; i++){
      ref.push_back('1' + i);
   }

   while (n >= 1){
      factorial /= n;
      res += ref[k/factorial];
      ref.erase(ref.begin() + k/factorial);
      k %= factorial;
      n--;
   }
   return res;
}
int main(int argc, char* argv[]){
   Solution sol;
   cout << sol.getPermutation(3,1) << endl;
}