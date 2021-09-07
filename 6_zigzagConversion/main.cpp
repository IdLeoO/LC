#include "main.hpp"
#include <iostream>
using namespace std;
int Solution::overCol(int length, int numRows){
    int overCols = 0;
    if (length % (2 * numRows - 2) > numRows){
        overCols = length % (2 * numRows - 2) - numRows + 1;
    }
    else if (length % (2 * numRows - 2) == 0){
        overCols = 0;
    }
    else{
        overCols = 1;
    }
    return overCols;
}

int Solution::Row(int length, int numRows){
    int Rows = 0;
    if (length % (2 * numRows - 2) > numRows ){
        Rows = numRows - (length % (2 * numRows - 2) - numRows) - 1;
    }
    else if (length % (2 * numRows - 2) == 0){
        Rows = 1;
    }
    else{
        Rows = length % (2 * numRows - 2) - 1;
    }
    return Rows;
}

string Solution::convert(string s, int numRows){
    if (numRows == 1){
        return s;
    }
    int colBulk = (s.size()) / (2 * numRows -2);
    int numColumns = colBulk * (numRows -1) + Solution::overCol(s.size(), numRows);
    char map[numRows][numColumns] = {};
    for (int i = 0; i < s.size(); i++){
        colBulk = (i + 1) / (2 * numRows -2);
        int col = colBulk * (numRows -1) + Solution::overCol(i + 1, numRows) -1;
        int row = Solution::Row(i + 1, numRows);
        char ptr = s[i];
        map[row][col] = ptr;
    }
    string result;
    for (int i = 0; i < numRows; i++ ){
        for (int j = 0; j < numColumns; j++){
            if (map[i][j] != 0){
                result += map[i][j];
            }
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    Solution sol;
    cout << argv[1] << " " << argv[2] << endl ;
    cout << sol.convert(argv[1], atoi(argv[2])) << endl;
    return 0;
}