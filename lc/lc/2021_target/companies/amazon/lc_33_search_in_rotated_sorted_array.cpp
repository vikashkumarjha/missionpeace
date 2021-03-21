/*
You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

*/

#include "header.hpp"


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if ( n == 0) return -1;


        int l = 0;
        int r = n - 1;

        while ( l <  r) {
            int m = l + ( r - l) / 2;
            if (nums[m] == target) return m;

            if (nums[m] < nums[r]) {
                if ( nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                }else {
                    r = m - 1;
                }
            }else if ( nums[m] > nums[r]) {
                if ( nums[m] > target && target >= nums[l]) {
                    r = m - 1;
                }else {
                    l = m + 1;
                }
            }    
        }
        if ( nums[l] == target) return l;

        return -1;



        
    }
};