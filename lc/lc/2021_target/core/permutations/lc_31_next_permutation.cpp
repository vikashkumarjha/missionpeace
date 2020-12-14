/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]

*/

#include "../header.hpp"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = 0;
        int n = nums.size() - 1;
        int flag = true;
        for ( int i = n; i > 0; i--) {
            if ( nums[i] > nums[i-1]) {
                pos = i - 1;
                flag = false;
                break;
            }
        }
        
        if ( flag) {
            sort(begin(nums), end(nums));
            return;
        }
        
       
        int a = nums[pos];
        int b = nums[pos+1];
        int idx = pos + 1;
        for ( int i = pos + 2; i <= n; i++) {
            if ( nums[i] > a && nums[i] < b) {
                b = nums[i];
                idx = i;
            }
        }
        nums[pos] = b;
        nums[idx] = a;
        
        sort(nums.begin() + pos + 1, nums.end());
        
        
    }
};