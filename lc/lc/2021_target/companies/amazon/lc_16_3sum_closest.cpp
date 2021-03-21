/*

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


*/

#include "header.hpp"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dist = INT_MAX;
        int res = -1;
        int n = nums.size();
        for ( int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n - 1;

            while ( l < r) {

                int currSum = nums[i] + nums[l] + nums[r];
                int diff = abs(currSum - target);
                if ( diff < dist) {
                    dist = diff;
                    res = currSum;
                }

                if ( currSum == target) {
                    return target;
                }
                else if ( currSum > target) {
                    r--;
                }else {
                    l++;
                }

            }


        }

        return res;

        
    }
};