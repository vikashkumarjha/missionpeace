/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if ( nums.empty()) return res;
        int n = nums.size();
        sort(begin(nums), end(nums));
        for ( int i = 0; i < n - 2; i++)
        {
            if ( nums[i] > 0) break;
            if ( i == 0 || ( i > 0 && nums[i] != nums[i-1])) {
                int l = i + 1;
                int r = n - 1;
                int target = 0 - nums[i];
                while ( l < r) {
                    int currSum = nums[l] + nums[r];
                    if ( currSum == target) {
                        res.push_back({nums[i], nums[l], nums[r]});
                        while ( l < r && nums[l] == nums[l+1]) l++; 
                        while ( l < r && nums[r] == nums[r-1]) r--; 
                        l++;
                        r--;
                    }
                    else if ( currSum > target) {
                        r--;
                    }
                    else {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
