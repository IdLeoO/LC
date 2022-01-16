#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix){
   vector<int> res;
   if (matrix.empty()) return res;
   int r = 0, l = matrix.size() - 1, j = matrix[0].size()  - 1, k = 0, m = 0, n = 0;
   int horizontal = 1, verticle = 0;
   while (m >= r && m <= l && n >= k && n <= j){
      res.push_back(matrix[m][n]);
      if (n == j && horizontal == 1){
         horizontal = 0;
         verticle = -1;
         r ++;
      }
      else if (m == l && verticle == -1){
         horizontal = -1;
         verticle = 0;
         j --;
      }
      else if (n == k && horizontal == -1){
         horizontal = 0;
         verticle = 1;
         l --;
      }
      else if (m == r && verticle == 1){
         horizontal = 1;
         verticle = 0;
         k ++;
      }

      switch (horizontal)
      {
      case 1:
         n++;
         break;
      case -1:
         n--;
      default:
         break;
      }

      switch (verticle)
      {
      case 1:
         m--;
         break;
      case -1:
         m++;
      default:
         break;
      }
   }
   return res;
}

int main(int argc, char* argv[]){
   Solution sol;

   vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
   auto result = sol.spiralOrder(matrix);
   for (auto &x: result){
      cout << x <<' ';
   }
   cout << endl;

}