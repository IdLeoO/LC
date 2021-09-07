#include "main.hpp"
#include <iostream>
#include <unordered_map>
//#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> rptCheck;
        // vector<char> subString;
        int subStringLength = 0;
        int rptPos = 0;
        for (int i = 0; i < s.size(); i++){
            if (rptCheck.find(s[i]) == rptCheck.end()){
                rptCheck.insert(make_pair(s[i], i + 1));
                // subString.push_back(s[i]);
            }
            else{                
                if (rptPos < rptCheck[s[i]]){
                    rptPos = rptCheck[s[i]];
                }
                rptCheck[s[i]] = i + 1;
            }
            subStringLength = max<int>(subStringLength, rptCheck[s[i]] - rptPos);
        }
        return subStringLength;
    }
};

int main(int args, char* argv[]){
    string input = "dvdf";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(input) << endl;


}