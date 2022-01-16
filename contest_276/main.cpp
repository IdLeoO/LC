// #include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
   public:
};
bool cmp(vector<int> a, vector<int> b){
   if (a[1] != b[1]){
      return a[1] < b[1];
   }
   else{
      return a[2] < b[2];
   }
}
// TLE, but correct
long long mostPoints(vector<vector<int>>& questions) {
         for (int i = 0; i < questions.size(); i++){
            int ft = i + questions[i][1];
            questions[i][1] = ft;
            questions[i].push_back(i);
        }
        sort(questions.begin(), questions.end(), cmp);
        for (auto &x: questions){
           for (auto& i: x){
              cout << i << ' ';
           }
           cout << endl;
        }
        vector<long long> dp(questions[questions.size() - 1][1] + 2);
        dp[0] = 0;
        int id = 0;
        for (int i = 1; i < dp.size(); i++){
           dp[i] = dp[i - 1];
           while (id < questions.size()){
              if (i - 1 == questions[id][1]){
                 dp[i] = max(dp[i], dp[questions[id][2]] + questions[id][0]);
                 id ++;
              }
              else break;
           }
        } 
        for (auto &x: dp){
           cout << x;
        }
        cout << endl;
        return dp[questions[questions.size() - 1][1] + 1];
    }





int main(int argc, char* argv[]){
   Solution sol;
   vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
   cout << mostPoints(questions)<<endl;
}