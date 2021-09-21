#include "main.hpp"
#include <iostream>

using namespace std;
vector<string> Solution::generateParenthesis(int n){
    vector<string> result;
    dfs("", n, 0, result);
    return result;
}

void Solution::dfs(string output, int leftNum, int rightNum, vector<string> &result){
    if (leftNum == 0 && rightNum == 0){
        result.push_back(output);
        return;
    }
    if (leftNum > 0){
        string outputNext = output + "(";
        int leftNext = leftNum - 1;
        int rightNext = rightNum + 1;
        dfs(outputNext, leftNext, rightNext, result);
    }
    if (rightNum > 0){
        string outputNext = output + ")";
        int rightNext = rightNum - 1;
        dfs(outputNext, leftNum, rightNext, result);
    }
}
int main(int argc, char* argv[]){
    Solution sol;
    vector<string> result = sol.generateParenthesis(atoi(argv[1]));
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}