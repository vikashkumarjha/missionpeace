/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

#include "../../header.hpp"


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


/*
int getMinCostPath(int A[M][N], int start_row, int start_col, int end_row, int end_col)
{
   if(start_row > end_row or start_col > end_col)
      return 0
   if(start_row == end_row and start_col == end_col)
      return A[start_row][start_col]
   //Recursive Calls
   int x = getMinCostPath(A, start_row, start_col+1, end_row, end_col)
   int y = getMinCostPath(A, start_row+1, start_col, end_row, end_col)
   int z = getMinCostPath(A, start_row+1, start_col+1, end_row, end_col)
   int minimum = min(x, y, z)
   return A[start_row][start_col] + minimum
}


*/


