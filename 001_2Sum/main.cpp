#include "main.hpp"
#include <string>

// Implementation
vector<int> Solution_basic::twoSum(vector<int>& nums, int target){
        vector<int> sol;
        for (int i = 0; i < nums.size(); i++){
                for (int j = i; j < nums.size(); j++){
                        if (nums[i] + nums[j] == target){
                                sol.push_back(nums[i]);
                                sol.push_back(nums[j]);
                                return sol;
                        }
                }
        }
        return sol;
}

vector<int> Solution_hash::twoSum(vector<int>& nums, int target){
        unordered_map<int, int> hashing;
        vector<int> sol;

        for (int i = 0; i <  nums.size(); i++){
                if (hashing.find(target - nums[i]) != hashing.end()){
                        sol.push_back(i);
                        sol.push_back(hashing[target-nums[i]]);
                        return sol;
                }
                hashing.insert(make_pair(nums[i], i));
        }
        return sol;
}
int main(int argc, char* argv[])
{
        Solution_hash result;
        vector<int> sol;
        vector<int> num;
        num.push_back(1);
        num.push_back(2);
        num.push_back(4);
        
        sol  = result.twoSum(num, 5);
        cout << sol[0] << sol[1] << endl ;
        return 0;
}       
