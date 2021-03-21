/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int level = 0;
       
        int start = 0;
        int end = 0;
        int maxreachableindex = INT_MIN;
       
        while (end < n - 1) {
            level++;

            for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1){
                    return level;
                }

                maxreachableindex = max(maxreachableindex, i + nums[i]);
            }
           
            start = end + 1;
            end = maxreachableindex;
        }
       
        return level;
    }
};
