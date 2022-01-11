#include "main.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> Solution::groupAnagrams(vector<string> & strs){
   unordered_map <string, int> store;
   vector<vector<string>> res;
   for (int i = 0; i < strs.size(); i++){
      string tmp = strs[i];
      sort(strs[i].begin(), strs[i].end());
      if (store.find(strs[i]) != store.end()){
         res[store[strs[i]]].push_back(tmp);
      }
      else{
         vector<string> a = {tmp};
         res.push_back(a);
         store[strs[i]] = res.size() - 1;
      }
   }
   return res;
}

int main(int argc, char* argv[]){
   Solution sol;
   //vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
   vector<string> strs = {""};
   for (vector<string> &x: sol.groupAnagrams(strs)){
      for (string &i: x){
         cout << i << ' ';
      }
      cout << endl;
   }
}