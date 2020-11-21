/*

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = nums[0];
        int currMax = nums[0];
        int result = nums[0];
        int N = nums.size();
        
        for ( int i = 1; i < N; i++ ) {
            int tmp = currMin;
            currMin = min( nums[i], min(currMax * nums[i] ,  currMin * nums[i]));
            currMax = max( nums[i], max(currMax * nums[i] ,  tmp * nums[i]));
            
            result = max(result, currMax);
        }
        
        return result;
        
        
    }
};