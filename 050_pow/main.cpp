#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

// double Solution::myPow(double x, int n){
//    long nl = n;
//    if (nl < 0){
//       x = 1/x;
//       nl = -nl;
//    }   
//    if (nl == 0){
//       return 1;
//    }
//    else {
//       if (nl % 2 == 1){
//          return x * myPow(x, nl - 1);
//       }
//       else{
//          double tmp = myPow(x, nl/2);
//          return tmp * tmp;
//       }
//    }
//    return x;
// }
double Solution::myPow(double x, int n){
   double res = 1;
   while (n) {
      if (n % 2) res = n > 0 ? res * x : res / x;
      x = x * x;
      n /= 2;
   }
   return res;
}

int main(int argc, char* argv[]){
   Solution sol;
   double x = 2;
   cout << sol.myPow(x, 10) << endl;
}