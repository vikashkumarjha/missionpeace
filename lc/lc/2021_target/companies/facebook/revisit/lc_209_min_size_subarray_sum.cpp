/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int minWindowSize = INT_MAX;
        int sum = 0;
        for ( r ; r < nums.size(); r++) {
            sum += nums[r];
            if ( sum >= s) {
                while ((sum - nums[l]) >= s) {
                    sum -= nums[l];
                    l++;
                }
                minWindowSize = min(minWindowSize, r - l + 1);
            }
          
        }
        return minWindowSize == INT_MAX ? 0 : minWindowSize;
        
    }
};


int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            if (sum >= s) {
                ans = min(ans, (j - i + 1));
                break; //Found the smallest subarray with sum>=s starting with index i, hence move to next index
            }
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}