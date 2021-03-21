/*
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 *       Output: 7
 *       Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 **/
//cost(i,j)=grid[i][j]+min(cost(i+1,j),cost(i,j+1))

class Solution {
public:
    int calculate(vector<vector<int>> &g, int r, int c, int R, int C) {
        if ( r == R || c == C) {
            return INT_MAX;
        }
        if ( r == R - 1 && c == C-1) {
            return g[r][c];
        }
        return g[r][c] + min(calculate(g, r+1, c, R, C) , calculate(g, r, c+1, R, C));
    }
    int minPathSum(vector<vector<int>>& grid) {
            if ( grid.empty()) return 0;
            int R = grid.size();
            int C = grid[0].size();
            return calculate(grid, 0, 0, R, C);
        }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if ( grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<int>> dp(R, vector<int>(C));
        
        dp[0][0] = grid[0][0];
        // fill the first row
        for ( int c = 1; c < C; c++) {
            dp[0][c] = dp[0][c-1] + grid[0][c];
        }
        
         // fill the first col
        for ( int r = 1; r < R; r++) {
            dp[r][0] = dp[r-1][0] + grid[r][0];
        }
        
        for ( int r = 1; r < R; r++) {
            for ( int c = 1; c < C; c++) {
                dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1]);
            }
        }
        
        return dp[R-1][C-1];
        
    }
};
