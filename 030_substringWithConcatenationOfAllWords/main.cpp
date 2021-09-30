#include "main.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> Solution::findSubstring(string s, vector<string>& words){
    vector<int> location;
    int wordLength = words[0].length();
    int combLength = words.size();
    if (wordLength > s.size()){
        return location;
    }
    unordered_map<string, int> wordMap;
    unordered_map<string, int> combMap;
    for (string word: words){
        wordMap[word] ++;
    }
    for (int j = 0; j < wordLength; j++){
        int begin = j;
        int sum = 0;
        combMap.clear();
        for (int i = j; i <= s.length() - wordLength; i += wordLength){
            string tmp = s.substr(i, wordLength);
            if (wordMap.count(tmp)){
                combMap[tmp] ++;
                sum ++;
                while (combMap[tmp] > wordMap[tmp]){
                    combMap[s.substr(begin, wordLength)] --;
                    begin += wordLength;
                    sum --;
                }
                if (sum == combLength){
                    location.push_back(begin);
                }
            }
            else{
                combMap.clear();
                sum = 0;
                begin = i + wordLength;
            }
        }
    }
    return location;
}

int main(int argc, char* argv[]){
    Solution sol;
    string s = "wordgoodgoodgoodbestword";
    string s1 = "barfoothefoobarman";
    string s2 = "aaaaaaaaaaaaaa";
    vector<string> words = {"word","good","best", "good"};
    vector<string> words1 = {"bar", "foo"};
    vector<string> words2 = {"aa", "aa"};
    auto result = sol.findSubstring(s2, words2);
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}