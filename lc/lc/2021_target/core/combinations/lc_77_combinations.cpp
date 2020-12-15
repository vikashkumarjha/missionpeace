/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

#include "../header.hpp"

class Solution {
public:
    void helper(int idx, int n, int k, vector<int> path, vector<vector<int>> &res) {
        if ( path.size() == k) {
            res.push_back(path);
            return;
        }
        
        
        for ( int i = idx; i <= n; i++) {
            path.push_back(i);
            helper(i+1, n, k, path, res);
            path.pop_back();
            
        }

    }
    
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        helper(1,n, k, path, res);
        return res;
        
        
    }
};