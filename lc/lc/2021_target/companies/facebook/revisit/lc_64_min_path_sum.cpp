/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if ( grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        //fill the first row
        
        for ( int i = 1; i < C; i++) {
            grid[0][i] += grid[0][i-1];    
        }
        //fill the first col
        for ( int i = 1; i < R; i++) {
            grid[i][0] += grid[i-1][0];    
        }
        
        for ( int i = 1; i < R; i++) {
            for ( int j = 1; j < C; j++) {
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[R-1][C-1];
        
    }
};