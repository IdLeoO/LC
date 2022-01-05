#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

string Solution::addBinary(string a, string b){
   string result = "";
   int aIdx = a.size() - 1, bIdx = b.size() - 1, carry = 0;
   string res = "";
   while (aIdx >= 0 || bIdx >= 0){
      int aVal = (aIdx >= 0 && a[aIdx] == '1') ? 1 : 0;
      int bVal = (bIdx >= 0 && b[bIdx] == '1') ? 1 : 0;
      int digitInt = aVal + bVal + carry;
      carry = (aVal + bVal + carry >= 2) ? 1 : 0;
      digitInt = (carry == 1) ? digitInt - 2 : digitInt;
      string digitStr = (digitInt == 0) ? "0" : "1";
      res = digitStr + res;
      if (aIdx <= 0 && bIdx <= 0 && carry == 1){
         res = "1" + res;
      }
      aIdx --;
      bIdx --;
   }
   return res;
}

int main(int argc, char* argv[]){
   Solution sol;
   string a = "1010", b = "1011";
   cout << sol.addBinary(a,b) << endl;
}