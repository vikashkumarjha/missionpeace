/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return bsearch(nums, 0, n-1);
        
    }
    
    int bsearch(vector<int> &nums, int l, int r) {
        if ( l == r )
            return l;
        int m = l + ( r - l)/2;
        if ( nums[m] > nums[m+1]) {
            return bsearch(nums, l, m);
        }
        return bsearch(nums, m+1, r);
    }
};