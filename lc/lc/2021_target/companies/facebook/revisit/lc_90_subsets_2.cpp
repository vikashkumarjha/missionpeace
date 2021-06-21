/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/
class Solution {
public:
    
    void helper(vector<int> &nums, int idx, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(path);
        
        
        for ( int i = idx; i < nums.size(); i++) {
            if ( i == idx || nums[i] != nums[i-1]) {
                path.push_back(nums[i]);
                helper(nums, i + 1, path, res);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        vector<int> path;
        
        helper(nums, 0, path, res);
        return res;
        
        
        
    }
};