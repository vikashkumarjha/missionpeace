/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while ( slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // cycle point need to ne found.
        slow = 0;
        while ( slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        if ( slow == 0) return -1;
        
        return slow;
        
    }
};