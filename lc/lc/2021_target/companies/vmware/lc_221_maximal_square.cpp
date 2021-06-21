/*
Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

*/

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if ( matrix.empty()) return 0;
        int R = matrix.size();
        int C = matrix[0].size();

        int maxLen = 0;
        vector<vector<int>> dp(R+1, vector<int>(C+1, 0));
        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( r == 0 || c == 0) {
                    dp[r][c] = matrix[r][c] - '0';
                }
                else {
                    if ( matrix[r][c] == '1') {
                        dp[r][c] = 1 + min(dp[r-1][c], min(dp[r][c-1], dp[r-1][c-1]));
                        
                    }
                }
                maxLen = max(maxLen, dp[r][c]);
            
            }
            
        }
        return maxLen * maxLen;
        
    }
};