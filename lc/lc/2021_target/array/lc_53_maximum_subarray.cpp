/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

*/
#include <iostream>
#include <vector>
using namespace std;

/***************************************
 Current max sum is max of :
      1. current element OR
      2. current element + Previous subarraysum

*****************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSubArr = nums[0];
        int maxSubArrSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            currSubArr   = max(nums[i], currSubArr + nums[i]);
            maxSubArrSum = max(maxSubArrSum, currSubArr);
        }

        return maxSubArrSum;
    }
};
