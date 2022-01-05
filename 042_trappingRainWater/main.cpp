#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
// Brute force
// int Solution::helper(vector<int>& height, int start, int end){
//     auto maxIt = max_element(height.begin() + start, height.begin() + end + 1);
//     int idx = maxIt - height.begin(), result = 0;
//     cout << idx << ' ' << *maxIt << endl;
//     if (start == 0){
//         result = *maxIt * (end - idx);
//         for (int i = idx + 1; i <= end; i++){
//             result -= height[i];
//         }
//         if (idx == 0){
//             return result;
//         }
//         result += helper(height, start, idx - 1);
//     }
//     else if (end == height.size() - 1){
//         result = *maxIt * (idx - start);
//         for (int i = start; i <= idx - 1; i++){
//             result -= height[i];
//         }
//         if (idx == height.size() - 1){
//             return result;
//         }
//         result += helper(height, idx + 1, end);
//     }
//     return result;
// }

// int Solution::trap(vector<int>& height){
//     auto maxIt = max_element(height.begin(), height.end());
//     int idx = maxIt - height.begin(), start = 0, end = height.size() - 1, result = 0;
//     cout << idx << endl;
//     if (idx == start){
//         result += helper(height, idx + 1, end);
//     }
//     else if(idx == end){
//         result += helper(height, start, idx - 1);
//     }
//     else{
//         result += helper(height, start, idx - 1) + helper(height, idx + 1, end);
//     }
//     return result;
// }

// dp
// int Solution::trap(vector<int>& height){
//     if(height.empty()) return 0;
//     int result = 0;
//     int size = height.size();
//     vector<int> left_max(size), right_max(size);
//     left_max[0] = height[0];
//     for (int i = 1; i < size; i++) {
//         left_max[i] = max(height[i], left_max[i - 1]);
//     }
//     right_max[size - 1] = height[size - 1];
//     for (int i = size - 2; i >= 0; i--) {
//         right_max[i] = max(height[i], right_max[i + 1]);
//     }
//     for (int i = 1; i < size - 1; i++) {
//         result += min(left_max[i], right_max[i]) - height[i];
//     }
//     return result;
// }

// two pointers using dp
int Solution::trap(vector<int>& height){
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
int main(int argc, char* argv[]){
    Solution sol;
    vector<int> height = {2,1,0,2};
    cout << sol.trap(height) << endl;
}