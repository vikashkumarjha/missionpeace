/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

*/

class Solution {
public:
    void helper(vector<int> &arr, int idx, int target, vector<int> &path, vector<vector<int>> &res) {
       
        if ( target == 0 ) {
            res.push_back(path);
            return;
        }
        
        if ( target < 0) return;
        
        for ( int i = idx; i < arr.size(); i++) {
            if ( i == idx || (arr[i] != arr[i-1])) {
                path.push_back(arr[i]);
                helper(arr, i+1, target - arr[i], path, res);
                path.pop_back();
            }
            
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<int> path;
        vector<vector<int>> res;
        helper(candidates, 0, target, path, res);
        
        return res;
        
        
    }
};