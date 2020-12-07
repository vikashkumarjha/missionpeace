/*


Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a majority element.

A majority element is an element that appears more than N/2 times in an array of length N.

 

Example 1:

Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: 
The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.


*/


class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int left, right;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        left = l;
        
        if(nums[l] != target) return false;

        r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2 + 1;
            if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        right = r;
        
        return (right-left+1) > nums.size()/2;
    }
};