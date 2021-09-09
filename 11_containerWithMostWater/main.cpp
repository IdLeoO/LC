#include "main.hpp"
using namespace std;
#include <iostream>
#include <string>
int Solution::maxArea(vector<int>& height){
    int start = 0;
    int end = height.size() - 1;
    int maxArea = 0;
    while (start < end){
        int tmpL = end - start;
        int tmpA = 0;
        if (height[start] < height[end]){
            tmpA = tmpL * height[start];
            start++;
        }
        else{
            tmpA = tmpL * height[end];
            end --;
        }
        if (tmpA > maxArea){
            maxArea = tmpA;
        }
    }
    return maxArea;
}

int main(int argc, char* argv[]){
    Solution sol;
    vector<int> height;
    string data;
    getline(cin, data);
    int pos = 0;

    while (string::npos != data.find_first_of(' ', pos)){ 
        string numStr = data.substr(pos, data.find_first_of(' ', pos) - pos); 
        pos = data.find_first_of(' ', pos) + 1;
        height.push_back(stoi(numStr));
    }

    cout << sol.maxArea(height) << endl;
    return 0;
}