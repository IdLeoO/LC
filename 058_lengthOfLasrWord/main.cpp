#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int Solution::lengthOfLastWord(string s){
   int len = 0;
   for (int i = s.size() - 1; i >= 0; i--){
      if (s[i] != ' '){
         len ++;
      }
      if (i < s.size() - 1 && s[i + 1] != ' ' && s[i] == ' '){
         break;
      }
   }
   return len;
}
int main(int argc, char* argv[]){
   Solution sol;
   string s = "world ";
   cout << sol.lengthOfLastWord(s) << endl;
}