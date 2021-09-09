#ifndef MAIN
#define MAIN

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*****
The basic 2sum algorithm is to find the matching numbers by iterating
in two layers with both layer of complexity O(n). The total is O(n^2)
*/

class Solution_basic{
        public:
                vector<int> twoSum(vector<int>& nums,int target);
};

/*****
Using hash table, the insertion and search complexity is O(1). The 
total is the outer layer O(n) with inner layer O(1), which is O(n)
*/

class Solution_hash{
        public:
                vector<int> twoSum(vector<int>& nums,int target);
};

#endif
