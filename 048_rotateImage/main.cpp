#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void Solution::rotate(vector<vector<int>> & matrix){
   for (int j = 0; j < matrix.size() / 2; j++){
      for (int i = 0; i < matrix.size(); i++){
         swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
      }
   }

   for (int i = 0; i < matrix.size(); i++){
      for (int j = matrix.size() - i - 2; j >= 0; j--){
         swap(matrix[i][j], matrix[matrix.size() - 1 - j][matrix.size() - 1 - i]);
      }
   }
}


int main(int argc, char* argv[]){
   Solution sol;
   vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16}};
   for (vector<int> &x: matrix){
      for (int &i: x){
         cout << i << ' ';
      }
      cout << endl;
   }
   cout << endl;

   sol.rotate(matrix);
   for (vector<int> &x: matrix){
      for (int &i: x){
         cout << i << ' ';
      }
      cout << endl;
   }

}