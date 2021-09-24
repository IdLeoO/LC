#include "main.hpp"
#include <iostream>
using namespace std;

// Brute force approach: O(mn)
int Solution::strStr(string haystack, string needle){
    if (needle == ""){
        return 0;
    }
    bool flag = false;
    for (int i = 0; i< haystack.size(); i++){
        if (haystack[i] == needle[0]){
            for (int j = 0; j < needle.size(); j++){
                if (haystack[i + j] != needle[j]){
                    break;
                }
                if (j == needle.size() - 1){
                    flag == true;
                    return i;
                }
            }
        }
    }
    return -1;
}

// KMP algorithm: Mnuth-Morris-Pratt algorithm
// Below is not KMP, only a modified version of brute force
int Solution::strStrKMP(string haystack, string needle){
    if (needle == ""){
        return 0;
    }
    bool flag = false;
    int i = 0;
    int limit = haystack.size() - needle.size();
    while (i <= limit){
        if (haystack[i] == needle[0]){
            int match = 0;
            for (int j = 0; j < needle.size(); j++){
                if ( j != 0 && haystack[i + j] == needle[0] && flag == false){
                    match = j;
                    flag = true;
                }
                if (haystack[i + j] != needle[j]){
                    if (flag == true){
                        i += match - 1;
                    }
                    else{
                        i += j - 1;
                    }
                    flag = false;
                    break;
                }
                if (j == needle.size() - 1){
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}

int main(int argc, char* argv[]){
    string haystack = "mississippi", needle = "issipi";
    Solution sol;
    cout << sol.strStrKMP(haystack, needle) << endl;
}