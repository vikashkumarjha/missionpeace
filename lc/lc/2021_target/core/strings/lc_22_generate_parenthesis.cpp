/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/

#include "../../header.hpp"


class Solution {
public:
    
    void helper(int n, string curr, int lCount, int rCount, vector<string> &res){
        if ( curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }
        
        if ( lCount < n) {
            
            helper(n, curr + "(", lCount+1, rCount, res);
        }
        
        if ( rCount < lCount) {
            
            helper(n, curr + ")", lCount, rCount+1, res);
        }
        
        
    }
    
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        helper(n, curr, 0, 0, res);
        return res;
        
        
    }
};