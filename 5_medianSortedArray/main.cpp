#include "main.hpp"

int main(int argc, char* argv[]){
    vector<int> num1;
    vector<int> num2;
    num1.push_back(1);
    num1.push_back(2);
    num2.push_back(3);
    num2.push_back(4);
    Solution result;
    cout << result.findMedianSortedArrays(num1, num2) << endl;
}