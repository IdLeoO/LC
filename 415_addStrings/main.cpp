#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

string Solution::addStrings(string num1, string num2){
   string res;
   int len1 = num1.size() - 1, len2 = num2.size() - 1, carry = 0;
   while (len1 >= 0 || len2 >= 0){
      int dgt1 = (len1 >= 0) ? num1[len1] - '0' : 0;
      int dgt2 = (len2 >= 0) ? num2[len2] - '0' : 0;
      int dgt = dgt1 + dgt2 + carry;
      carry = (dgt > 9) ? 1 : 0;
      dgt = (carry == 1) ? dgt - 10 : dgt;
      res.push_back('0' + dgt);
      if ((len1 <= 0 && len2 <= 0) && carry == 1){
         res.push_back('0' + 1);
      }
      len1 --;
      len2 --;
   }
   reverse(res.begin(), res.end());
   return res;
}
int main(int argc, char* argv[]){
   Solution sol;
   string num1 = "0", num2 = "0";
   cout << sol.addStrings(num1, num2) << endl;
}