#ifndef MAIN
#define MAIN
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    // let nums1 be shorter vector
    if (nums1.size() > nums2.size()){
        return findMedianSortedArrays(nums2, nums1);
    }
    int div1 = 0 , div2 = 0, avr = (nums1.size() + nums2.size() + 1) >> 1, low = 0, high = nums1.size();
    while (low <= high){
        div1 = (low + high) >> 1;
        div2 = avr - div1;
        // div pointing to the right of the division line
        int left1 = (div1 > 0) ? nums1[div1 - 1] : -2000000;
        int right1 = (div1 < nums1.size()) ? nums1[div1] : 2000000;
        int left2 = (div2 > 0) ? nums2[div2 - 1] : -2000000;
        int right2 = (div2 < nums2.size()) ? nums2[div2] : 2000000;
        
        if (left1 <= right2 && right1 >= left2){
            if ((nums1.size() + nums2.size()) % 2 == 1){
                return max(left1, left2);
            }
            else{
                return double((max(left1, left2) + min(right1, right2))) / 2;
            }
        }
        else if(left1 > right2){
            high = div1 - 1;
        }
        else{
            low = div1 + 1;
        }
    }
    return 0;
}
#endif