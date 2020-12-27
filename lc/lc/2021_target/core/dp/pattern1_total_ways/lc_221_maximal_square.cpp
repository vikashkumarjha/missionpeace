/*

Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

*/

#include "../../header.hpp"



class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        int R = m.size();
        if ( R == 0) return 0;
        int C = m[0].size();
        vector<vector<int>> dp(R+1, vector<int>(C+1, 0));
        
        int maxLength = INT_MIN;
        
        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( r == 0  || c == 0) {
                    dp[r][c] = m[r][c] - '0';
                }else {
                    if ( m[r][c] == '1') {
                        dp[r][c] =  min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]) + 1;
                    }
                }
                
                maxLength = max(maxLength, dp[r][c]);
            }
            
        }
        
        return maxLength * maxLength;
        
        
    }
};