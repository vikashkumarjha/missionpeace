/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

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

/*

public class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}

*/


