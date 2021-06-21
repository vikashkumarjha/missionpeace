Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 0, cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i] ? 1 : -1;
            if (m.count(cur))
                ans = max(ans, i - m[cur]);
            else
                m[cur] = i;
        }
        return ans;
        
    }
};