// #include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

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

class Solution {
public:
    void dfs(vector<vector<int>>& statements, vector<int>& trTable, int& maxTr){
        int truth = 0;
        if (trTable.size() == statements.size()){
            for (int i = 0; i < trTable.size(); i++){
                if (trTable[i] == 1){
                    for (int j = 0; j < statements.size(); j++){
                        if (statements[i][j] == 0 && trTable[j] != 0){
                            return;
                        }
                    }
                    truth ++;
                }
            for (int x: trTable){
               cout << x << ' ';
            }
            cout << endl;
            maxTr = max(truth, maxTr);
            return;
        }
        
        trTable.push_back(1);
        dfs(statements, trTable, maxTr);
        trTable.pop_back();
        
        trTable.push_back(0);
        dfs(statements, trTable, maxTr);
        trTable.pop_back();
    }
    
    int maximumGood(vector<vector<int>>& statements) {
        vector<int> trTable;
        int max = 0;
        dfs(statements, trTable, max);
        return max;
    }
};



class Solution1 {
public:
    int n, ans = 0;
    int maximumGood(vector<vector<int>>& S) {
        n = S.size();
        string cur = ""; cur.reserve(n);
        dfs(S, cur, 0, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& S, string& cur, int i, int cnt) {
        if(i == n) {
			// if valid, update ans to store maximum good person found till now
            if(valid(S, cur)) {
               ans = max(ans, cnt);
               cout << cur << endl;
            }
            
            return;
        }
        cur.append(1, '0');
        dfs(S, cur, i+1, cnt);        // assuming ith person is bad
        cur.back() = '1';
        dfs(S, cur, i+1, cnt + 1);    // assuming ith person is good
        cur.pop_back();        
    }
    bool valid(vector<vector<int>>& S, string& cur) {
        for(int i = 0; i < n; i++) 
            if(cur[i] == '1') 
                for(int j = 0; j < n; j++) 
                    if(S[i][j] != 2 && S[i][j] != cur[j] - '0') return false;
        return true;
    }
};



int main(int argc, char* argv[]){
   Solution sol;
   Solution1 sol1;
   vector<vector<int>> nums = {{2,1,0,0,2}, {2,2,1,0,2},{0,2,2,1,0},{2,0,0,2,0}, {2,0,0,1,2}};
   cout << sol.maximumGood(nums)<<endl;


}