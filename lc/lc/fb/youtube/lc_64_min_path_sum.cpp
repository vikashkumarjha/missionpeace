/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        if ( !R )
            return 0;
        int C = grid[0].size();
        vector<vector<int>> dp(R, vector<int>(C));
        dp[0][0] = grid[0][0];
        // fill the first row
        for ( int i = 1; i < C; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        // fill the first column
        for ( int i = 1; i < R; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for ( int i = 1; i < R; i++) {
            for ( int j = 1; j < C; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[R-1][C-1];



    }
};`
