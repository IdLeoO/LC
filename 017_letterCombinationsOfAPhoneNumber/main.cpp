#include "main.hpp"
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> Solution::letterCombinations(string digits){
    vector<string> result = {};
    unordered_map<int, vector<string>> keyboard;
    string a = "a";
    for (int i = 0; i < 8; i++){
        vector<string> key;
        for (int j = 0; j < 3; j++){
            key.push_back(a);
            a[0]++;
        }
        if (i == 5){
            key.push_back(a);
            a[0]++;
        }
        keyboard.insert(make_pair(i+2, key));
    }
    keyboard[9].push_back("z");
    vector<vector<string>> keys;
    if (digits == ""){
        return result;
    }
    reverse(digits.begin(), digits.end());
    int number = stoi(digits);
    for (int i = 0; i < digits.size(); i++){
        if (keyboard.find(number % 10) == keyboard.end()){
            number /= 10;
            continue;
        }
        keys.push_back(keyboard[number % 10]);
        number /= 10;
    }

    int layer = 0;
    string startNode = "";
    DFS(keys, layer, result, startNode);
    return result;
}

void Solution::DFS(vector<vector<string>> &keys, int layer, vector<string> &result, string output){
    if (keys.size() == 0){
        return;
    }
    for (int i = 0; i < keys[layer].size(); i++){
        string outputStack = output + keys[layer][i];
        if (layer < keys.size() - 1){
            int layerNext = layer + 1;
            DFS(keys, layerNext, result, outputStack);
        }
        else{
            result.push_back(outputStack);
        }
    }
}

int main(int argc, char* argv[]){
    Solution sol;
    string digits = "7";
    vector<string> out = sol.letterCombinations(digits);
    for (int i = 0; i < out.size(); i++){
        cout << out[i] << " ";
    }
    cout <<endl;


    return 0;
}