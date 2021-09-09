#include "main.hpp"
#include <string>
#include <iostream>

using namespace std;

int Solution::reverse(int x){
    string xd = to_string(x);
    string xRe = "";
    for (int i = xd.size() - 1; i >= 0; i--){
        if (xd[i] == '-'){
            xRe.insert(xRe.begin(), xd[i]);
        }
        else{
            xRe += xd[i];
        }
    }
    int result = 0;
    try{
        result = stoi(xRe);
    }
    catch (out_of_range&){
        return 0;
    }
    return result;
}

int main(int argc, char* argv[]){
    Solution sol;
    cout << sol.reverse(atoi(argv[1])) << endl;
}