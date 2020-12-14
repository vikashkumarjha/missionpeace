/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


*/

#include "../header.hpp"

class Solution {
public:
    
    void helper(vector<int> &nums, int idx, vector<vector<int>> &res) {
        if ( idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        unordered_set<int> m;
        
        for (  int k = idx; k < nums.size(); k++) {
            if ( m.count(nums[k])) continue;
            m.insert(nums[k]);
            swap(nums[idx], nums[k]);
            helper(nums, idx+1, res);
            swap(nums[idx], nums[k]);
        }
        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if ( nums.empty()) return res;
        
        helper(nums, 0, res);
        
        return res;
        
        
        
    }
};