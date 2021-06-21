/*Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

 

Example 1:

Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.

*/



class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int sum = 0;
        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(!m.count(sum)) {
                m[sum] = i;
            }
            if(sum == k) {
                maxlen = i + 1;
            }
            if(m.count(sum - k) > 0){ 
                 maxlen = max(maxlen, i - m[sum - k]);
            }
        }
        return maxlen;
    }
};