/*
Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l = 0;
        int r = 1;
        int N = nums.size();
        if ( nums.empty()) return 0;
        int globalMax = INT_MIN;
        int res = 1;
        for (; r < N; r++) {
            if ( nums[r] > nums[r-1]) {
                res++;
            }else {
                globalMax = max(globalMax, res);
                res = 1;
                
            }
            
        }
        globalMax = max(globalMax, res);
        return globalMax;
        
    }
};