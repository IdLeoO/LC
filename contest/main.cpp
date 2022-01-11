// #include "main.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
};

int main(int argc, char* argv[]){
   Solution sol;
   vector<int> nums = {0,1,1,1,0,0,1,1,0};
   vector<string> s = {"tqnu", "qut"};
   vector<string> t = {"mtqnu", "qutn"};
   //cout<< sol.wordCount(s, t) << endl;
   cout << sol.minSwaps(nums)<<endl;
}