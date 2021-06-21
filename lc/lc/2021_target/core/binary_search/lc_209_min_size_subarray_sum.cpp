/*

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

*/



class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int winSize = INT_MAX;
        int l = 0;
        int r = 0;
        int sum = 0;
        for ( r; r < nums.size(); r++) {
            sum += nums[r];
            if ( sum >= s) {
                while ( (sum - nums[l]) >= s) {
                    sum -= nums[l];
                    l++;
                }
                winSize = min(winSize, r -l + 1);
            }

        }

        return ( winSize == INT_MAX ? 0 : winSize);
       
    }
};