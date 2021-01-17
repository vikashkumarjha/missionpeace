/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/

// ( sum - k) + y = sum;
// y = k;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        
        for ( auto n : nums) {
            sum += n;
            if ( m.count(sum - k)) {
                res += m[sum-k];
            }
            m[sum]++;
            
        }
        
        return res;
        
        
    }
};