/*
Given an integer array nums, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

class Solution {
public:
    void helper(vector<int> &nums,int idx,  vector<int> path, vector<vector<int>> &res) {
        res.push_back(path);
        
        for ( int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            helper(nums, i+1, path, res);
             path.pop_back();
        }
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(nums,0, path, res);
        return res;
        
    }
};