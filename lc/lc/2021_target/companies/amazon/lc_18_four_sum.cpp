/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []

*/

#include "header.hpp"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int N = nums.size();
    vector<vector<int>> res;
    
    if ( N < 4)
        return res;
    
    std::sort(nums.begin(), nums.end());
    
    for ( int i = 0; i < N - 3; i++) {
        if ( (i > 0) && (nums[i-1] == nums[i])) continue;
        
        for ( int j = i + 1; j < N - 2; j++) {
            if ( j > i+1 && nums[j-1] == nums[j]) continue;
            int l = j + 1;
            int r = N -1;
            
            while ( l < r ) {
                int currSum = nums[i] + nums[j] + nums[l] + nums[r];
                if ( currSum < target) {
                    l++;
                }else if ( currSum > target) {
                    r--;
                }else {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                    
                    while(l < r and nums[l] == nums[l-1]) l++;
                    while(l < r and nums[r] == nums[r+1]) r--;
                    
                }
                
            }
        
        }
        
        
    }
    return res;
    }
    
};